cmake_minimum_required(VERSION 3.23)
project(P02)

set(CMAKE_CXX_STANDARD 14)

add_executable(P02
        src/Komponente.cpp
        src/Bohrung.cpp
        src/Fraesung.cpp
        src/Iterator.cpp
        src/DeList.cpp
        src/Werkstueck.cpp
        p02Main.cpp
        )

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
