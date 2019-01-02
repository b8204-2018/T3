cmake_minimum_required(VERSION 3.12)
project(T3)

set(CMAKE_CXX_STANDARD 17)

#Add the google test subdirectory
add_subdirectory(googletest)

#include googletest/include dir
include_directories(googletest/googletest/include)

#include the googlemock/include dir
include_directories(googletest/googlemock/include)

add_executable(T3
        src/base64.cpp
        src/base64.hpp
        main.cpp ${SOURCE_FILES})
target_link_libraries(T3
        src/base64.cpp
        src/base64.hpp
        main.cpp gtest gtest_main)
target_link_libraries(T3
        src/base64.cpp
        src/base64.hpp
        main.cpp gmock gmock_main)