cmake_minimum_required(VERSION 3.0)
project(kvasir_mpl)

include(CTest)

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

if(BUILD_TESTING)
	add_executable(kvasir_mpl_test test/test.cpp)
	target_link_libraries(kvasir_mpl_test kvasir_mpl)
	target_compile_options(kvasir_mpl_test PUBLIC -ftemplate-depth=2048 -Wall) # -std=gnu++1z)
endif()

option(MAKE_INCLUDE_TESTS OFF)
if (BUILD_TESTING AND MAKE_INCLUDE_TESTS)
	function(convert_name out filename)
		string(REGEX REPLACE "[\\./]" "_" result "${filename}")
		set(${out} ${result} PARENT_SCOPE)
	endfunction()
	function(make_test_includes_file file)
		convert_name(basename "${file}")
		file(WRITE ${CMAKE_BINARY_DIR}/include_test/${basename}.cpp
				"#include <${file}>\nint main() {}")
	endfunction()
	file(GLOB_RECURSE headers RELATIVE "${CMAKE_CURRENT_LIST_DIR}/src/"
			"${CMAKE_CURRENT_LIST_DIR}/src/*.hpp")
	foreach(file IN LISTS headers)
		make_test_includes_file(${file})
		convert_name(basename "${file}")
		add_executable(${basename} include_test/${basename}.cpp)
		target_link_libraries(${basename} kvasir_mpl)
		target_compile_options(${basename} PUBLIC -Wall)
		add_dependencies(kvasir_mpl_test ${basename})
	endforeach()
	file(GLOB_RECURSE tests RELATIVE "${CMAKE_CURRENT_LIST_DIR}/"
			"${CMAKE_CURRENT_LIST_DIR}/test/*.hpp")
	foreach (file IN LISTS tests)
		make_test_includes_file(${file})
		convert_name(basename "${file}")
		add_executable(${basename} include_test/${basename}.cpp)
		target_link_libraries(${basename} kvasir_mpl)
		target_include_directories(${basename} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
		target_compile_options(${basename} PUBLIC -Wall)
		add_dependencies(kvasir_mpl_test ${basename})
	endforeach ()
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
