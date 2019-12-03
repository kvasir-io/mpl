cmake_minimum_required(VERSION 3.0)
project(kvasir_mpl)

# create the kvasir_mpl library target
add_library(kvasir_mpl INTERFACE)
target_include_directories(kvasir_mpl INTERFACE
		$<INSTALL_INTERFACE:include>
		$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>)
# mpl requires a number of features to compile, this will automatically set the c++ standard version
# to support those features. The c++ version is not explicitly set, so that cmake can figure
# things out by itself
target_compile_features(kvasir_mpl INTERFACE
		cxx_variadic_templates
		cxx_constexpr
		cxx_alias_templates
		cxx_auto_type
		cxx_long_long_type
		cxx_right_angle_brackets
		cxx_static_assert
		cxx_uniform_initialization
		cxx_user_literals
		${CPP_EXTRA_FEATURES})

option(BUILD_TESTING OFF)
option(MAKE_INCLUDE_TESTS OFF)
if (MAKE_INCLUDE_TESTS)
	include(ExternalProject)
	ExternalProject_Add(metacheck
			PREFIX metacheck
			GIT_REPOSITORY https://github.com/chieltbest/metacheck.git
			GIT_TAG origin/development
			CONFIGURE_COMMAND ""
			BUILD_COMMAND ""
			INSTALL_COMMAND ""
			TEST_COMMAND ""
			EXCLUDE_FROM_ALL YES)

	ExternalProject_Get_Property(metacheck source_dir)
	set(metacheck_source_dir ${source_dir})

	add_custom_target(kvasir_mpl_test_always_run
		COMMAND touch test/test.cpp
		WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

	add_executable(kvasir_mpl_test test/test.cpp
			test/algorithm/all.cpp
			test/algorithm/any.cpp
			test/algorithm/count_if.cpp
			test/algorithm/filter.cpp
			test/algorithm/find_if.cpp
			test/algorithm/flatten.cpp
			test/algorithm/fold_left.cpp
			test/algorithm/fold_right.cpp
			test/algorithm/lookup.cpp
			test/algorithm/make_sequence.cpp
			test/algorithm/partition.cpp
			test/algorithm/product.cpp
			test/algorithm/remove_adjacent.cpp
			test/algorithm/remove_if.cpp
			test/algorithm/reverse.cpp
			test/algorithm/sort.cpp
			test/algorithm/split_if.cpp
			test/algorithm/stable_sort.cpp
			test/algorithm/transform.cpp
			test/algorithm/zip_with.cpp
			test/functional/bind.hpp
			test/functional/call.hpp
			test/functional/compose.hpp
			test/functional/fork.hpp
			test/functional/identity.hpp
			test/functions/arithmetic/decrement.hpp
			test/functions/arithmetic/divide.hpp
			test/functions/arithmetic/increment.hpp
			test/functions/arithmetic/invert.hpp
			test/functions/arithmetic/max.hpp
			test/functions/arithmetic/min.hpp
			test/functions/arithmetic/minus.hpp
			test/functions/arithmetic/modulo.hpp
			test/functions/arithmetic/negate.hpp
			test/functions/arithmetic/plus.hpp
			test/functions/arithmetic/times.hpp
			test/functions/bitwise/bitwise_and.hpp
			test/functions/bitwise/bitwise_complement.hpp
			test/functions/bitwise/bitwise_or.hpp
			test/functions/bitwise/bitwise_xor.hpp
			test/functions/comparison/equal.hpp
			test/functions/comparison/greater_than.hpp
			test/functions/comparison/greater_than_or_equal.hpp
			test/functions/comparison/less_than.hpp
			test/functions/comparison/less_than_or_equal.hpp
			test/functions/comparison/not_equal.hpp
			test/functions/logical/logical_and.hpp
			test/functions/logical/logical_not.hpp
			test/functions/logical/logical_or.hpp
			test/sequence/at.hpp
			test/sequence/is_list.hpp
			test/sequence/join.hpp
			test/sequence/lookup.cpp
			test/sequence/pop_front.hpp
			test/sequence/push_back.hpp
			test/sequence/push_front.hpp
			test/sequence/size.cpp
			test/types/bool.hpp
			test/types/int.hpp
			test/types/integral_constant.hpp
			test/types/list.hpp
			test/types/nothing.hpp
			test/utility/always.hpp
			test/utility/conditional.hpp
			test/utility/is_instance.hpp
			test/testing.hpp)
	target_compile_options(kvasir_mpl_test PUBLIC -ftemplate-depth=2048 -Wall
			-ftemplate-backtrace-limit=0)
	target_link_libraries(kvasir_mpl_test kvasir_mpl)
	add_dependencies(kvasir_mpl_test metacheck kvasir_mpl_test_always_run)
	target_include_directories(kvasir_mpl_test PRIVATE
			${CMAKE_BINARY_DIR}/mpl/metacheck/src/metacheck/src/)
	set_target_properties(kvasir_mpl_test PROPERTIES CXX_STANDARD 14)
	set(CMAKE_CXX_STANDARD_REQUIRED YES)
	set(CMAKE_CXX_EXTENSIONS NO)

	if (MAKE_INCLUDE_TESTS)
		function(convert_name out filename)
			string(REGEX REPLACE "[\\./]" "_" result "${filename}")
			set(${out} ${result} PARENT_SCOPE)
		endfunction()
		function(make_test_includes_file file)
			convert_name(basename "${file}")
			file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/include_test/${basename}.cpp
					"#include <${file}>\nint main() {}")
		endfunction()
		function(make_tests headers)
			foreach (file IN LISTS ${headers})
				make_test_includes_file(${file})
				convert_name(basename "${file}")
				add_executable(${basename} EXCLUDE_FROM_ALL
						${CMAKE_CURRENT_BINARY_DIR}/include_test/${basename}.cpp)
				target_link_libraries(${basename} kvasir_mpl)
				target_compile_options(${basename} PUBLIC -Wall)
				add_dependencies(kvasir_mpl_test ${basename})
				set_target_properties(${basename} PROPERTIES CXX_STANDARD 14)
				add_dependencies(${basename} metacheck)
				target_include_directories(${basename} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
						${metacheck_source_dir}/src/)
			endforeach ()
		endfunction()
		file(GLOB_RECURSE sources RELATIVE "${CMAKE_CURRENT_LIST_DIR}/src/"
				"${CMAKE_CURRENT_LIST_DIR}/src/*.hpp")
		make_tests(sources)
		file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_LIST_DIR}/"
				"${CMAKE_CURRENT_LIST_DIR}/test/*.hpp")
		make_tests(tests)
	endif ()
endif ()

# Add Standardese target
find_program(STANDARDESE standardese HINTS ${STANDARDESE_ROOT})

if (STANDARDESE)
	set(KVASIR_MPL_DOCS_DIR ${CMAKE_BINARY_DIR}/doc/standardese)
	message(STATUS "Found standardese for documentation generation")
	message(STATUS "Documentation dir is: ${KVASIR_MPL_DOCS_DIR}")
	file(MAKE_DIRECTORY ${KVASIR_MPL_DOCS_DIR})
	add_custom_target(
			standardese
			COMMAND standardese
			-I${CMAKE_SOURCE_DIR}/src/kvasir/mpl
			--input.blacklist_namespace=detail
                        --input.blacklist_namespace=eager
			--output.require_comment_for_full_synopsis=false
			--output.format=html
			${CMAKE_SOURCE_DIR}/src/kvasir/mpl
			WORKING_DIRECTORY ${KVASIR_MPL_DOCS_DIR}
	)
endif (STANDARDESE)

include(GNUInstallDirs)

install(DIRECTORY src/
	DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(TARGETS kvasir_mpl
	EXPORT kvasir_mplConfig
	DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

install(EXPORT kvasir_mplConfig
	DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake/kvasir_mpl"
)
