cmake_minimum_required(VERSION 3.14)

set(prj_name "p01")

project(${prj_name})

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

add_executable(
  ${prj_name}
  komponentenList.cpp
  fraesung.cpp
  P01Main.cpp
)


# commands to build and execute
# cmake -S . -B build
# cmake --build build
# cd build && ctest