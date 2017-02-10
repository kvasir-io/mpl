cmake_minimum_required(VERSION 3.0)
project(po2_metalib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ftemplate-depth=2048 -std=c++11")

add_executable(mpl_test test/test.cpp)