cmake_minimum_required(VERSION 3.10)
project(test_project)

set(CMAKE_CXX_STANDARD 17)

add_library(print_lib src/test.cpp)

target_include_directories(print_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include)