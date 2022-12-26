cmake_minimum_required(VERSION 3.23)
project(CLionP)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")

add_executable(CLionP
        fraesung.cpp
        komponentenList.cpp
        P01Main.cpp
        )
