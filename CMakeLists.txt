cmake_minimum_required(VERSION 3.12)
project(T3)

set(CMAKE_CXX_STANDARD 17)

add_executable(T3 src/base64.cpp src/base64.hpp main.cpp)
