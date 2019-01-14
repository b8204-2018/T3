cmake_minimum_required(VERSION 3.12)
project(untitled10)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest)

include_directories(lib/googletest/googletest/include)

include_directories(src)

add_executable(untitled10 main.cpp src/base64.cpp src/base64.h)

add_executable(Tests
        tests.cpp src/base64.h src/base64.cpp)

target_link_libraries(untitled10 gtest gtest_main)