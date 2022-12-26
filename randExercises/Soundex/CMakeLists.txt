cmake_minimum_required(VERSION 3.24.2)
project(soundex)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CTest)
enable_testing()

add_executable(${PROJECT_NAME} soundex.cpp testSoundexMain.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# execute_process(COMMAND)
