cmake_minimum_required(VERSION 3.13)
project(T3)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(libs/googletest)

include_directories(libs/googletest/googletest/include)

include_directories(src)

add_executable(T3
        src/base64.cpp
        src/base64.hpp
        CMakeLists.txt
        main.cpp)

target_link_libraries(T3 gtest gtest_main)