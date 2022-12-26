cmake_minimum_required(VERSION 3.24)
project(numcpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(numcpp main.cpp cmake-build-debug/array.cpp cmake-build-debug/array.hpp)
