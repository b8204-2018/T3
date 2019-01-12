cmake_minimum_required(VERSION 3.13)
project(T3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)

add_executable(T3 main.cpp src/operations.cpp src/operations.h)

target_link_libraries(T3 gtest gtest_main)