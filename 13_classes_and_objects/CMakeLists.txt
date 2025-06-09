cmake_minimum_required(VERSION 3.10)

project(13_classes_and_objects)

include_directories(include) 

add_executable(00_declare_class_and_objects src/00_declare_class_and_objects.cpp)
add_executable(01_accessing_class_members src/01_accessing_class_members.cpp)
add_executable(02_access_modifiers src/02_access_modifiers.cpp)
add_executable(03_implementing_methods src/03_implementing_methods.cpp)
add_executable(04_account src/main.cpp src/04_account.cpp)