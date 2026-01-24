cmake_minimum_required(VERSION 3.10)

project(cherno)

include_directories(include)

add_executable(log src/log.cpp)
add_executable(recap include/recap.h src/recap.cpp)

add_executable(16a_raw_pointers_stack src/16a_raw_pointers_stack.cpp)
add_executable(16b_raw_pointer_heap src/16b_raw_pointer_heap.cpp)
add_executable(16c_pass_by_examples src/16c_pass_by_examples.cpp)
add_executable(23_enum src/23_enum.cpp)
add_executable(24_25_constructor_destructor src/24_25_constructor_destructor.cpp)
add_executable(26_inheritance src/26_inheritance.cpp)
add_executable(27_virtual_functions src/27_virtual_functions.cpp)
add_executable(28_interfaces src/28_interfaces.cpp)
add_executable(29_visibility src/29_visibility.cpp)
add_executable(30_arrays src/30_arrays.cpp)
add_executable(31_strings src/31_strings.cpp)

