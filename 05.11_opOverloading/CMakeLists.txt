cmake_minimum_required(VERSION 3.0.0)
set (CMAKE_CXX_STANDARD 14)
project(Punkt3D VERSION 0.1.0)

add_executable(
    Punkt3D
    punkt3d.cpp
    20221104Main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
