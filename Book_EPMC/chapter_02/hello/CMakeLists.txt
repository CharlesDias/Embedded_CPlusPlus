cmake_minimum_required(VERSION 3.5.1)

set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabi-g++)
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

SET(CMAKE_CXX_FLAGS "-g --std=c++17")  # Pass the -g parameter to the compiler. 
                                       # This parameter instructs the compiler to add debug symbols to the resulting binary. 

project(hello)

add_executable(hello hello.cpp)