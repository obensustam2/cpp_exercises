cmake_minimum_required(VERSION 3.10)

project(cherno)

# Adding include headers into project
add_library(project_includes INTERFACE)
target_include_directories(project_includes INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(16a_raw_pointers_stack src/16a_raw_pointers_stack.cpp)
add_executable(16b_raw_pointer_heap src/16b_raw_pointer_heap.cpp)
add_executable(16c_pass_by_examples src/16c_pass_by_examples.cpp)

add_executable(18_oop src/18_main.cpp src/18_classes.cpp)
target_link_libraries(18_oop PRIVATE project_includes)

add_executable(23_enum src/23_enum.cpp)
add_executable(24_25_constructor_destructor src/24_25_constructor_destructor.cpp)
add_executable(26_inheritance src/26_inheritance.cpp)
add_executable(27_virtual_functions src/27_virtual_functions.cpp)
add_executable(28_interfaces src/28_interfaces.cpp)
add_executable(29_visibility src/29_visibility.cpp)
add_executable(30_arrays src/30_arrays.cpp)
add_executable(31_strings src/31_strings.cpp)
add_executable(33_const_keyword src/33_const_keyword.cpp)
add_executable(37_object_types src/37_object_types.cpp)
add_executable(40_operator_overloading src/40_operator_overloading.cpp)
add_executable(41_this_keyword src/41_this_keyword.cpp)
add_executable(43a_smart_pointers_unique src/43a_smart_pointers_unique.cpp)
add_executable(43b_smart_pointers_shared src/43b_smart_pointers_shared.cpp)
add_executable(44_copy_constructors src/44_copy_constructors.cpp)
add_executable(45_arrow_operator_with_shared_pointer src/45_arrow_operator_with_shared_pointer.cpp)
add_executable(46_vector src/46_vector.cpp)
add_executable(48_local_static src/48_local_static.cpp)

# Point to the test_project's CMakeLists.txt to access print_lib
add_subdirectory(
    /home/oben/Projects/cpp_exercises/test_project
    ${CMAKE_BINARY_DIR}/test_project)
add_executable(49_external_project src/49_external_project.cpp)
target_link_libraries(49_external_project PRIVATE print_lib)

add_executable(52_multiple_return src/52_multiple_return.cpp)
add_executable(53_templates src/53_templates.cpp)
add_executable(54_stack_and_heap_memory src/54_stack_and_heap_memory.cpp)
add_executable(57_static_arrays src/57_static_arrays.cpp)
add_executable(58_raw_function_pointers src/58_raw_function_pointers.cpp)
add_executable(59_lambdas src/59_lambdas.cpp)
add_executable(60_namespaces src/60_namespaces.cpp)

find_package(Threads REQUIRED)
add_executable(62_threads src/62_threads.cpp)
target_link_libraries(62_threads PRIVATE Threads::Threads)

add_executable(63_timing src/63_timing.cpp)
add_executable(64_multidimensional_arrays src/64_multidimensional_arrays.cpp)
add_executable(65_sorting src/65_sorting.cpp)
add_executable(68_virtual_destructors src/68_virtual_destructors.cpp)
add_executable(69_casting src/69_casting.cpp)