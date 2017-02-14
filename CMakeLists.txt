cmake_minimum_required(VERSION 2.6)
project(kvasir_mpl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-depth=2048 -std=c++11")

add_executable(mpl_test test/test.cpp)