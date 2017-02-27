cmake_minimum_required(VERSION 3.0)
project(kvasir_mpl)

# create the kvasir_mpl library target
add_library(kvasir_mpl INTERFACE)
target_include_directories(kvasir_mpl INTERFACE
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
		cxx_user_literals)

add_executable(kvasir_mpl_test test/test.cpp)
target_link_libraries(kvasir_mpl_test kvasir_mpl)
target_compile_options(kvasir_mpl_test PUBLIC -ftemplate-depth=2048 -std=gnu++1z)