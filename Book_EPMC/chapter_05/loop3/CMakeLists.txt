cmake_minimum_required(VERSION 3.5.1)
project(loop)
add_executable(loop loop.cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# RELEASE build
set(CMAKE_CXX_FLAGS_RELEASE "--std=c++17")

# DEBUG build
# Pass the -g parameter to the compiler. This parameter instructs the compiler to add debug 
# symbols to the resulting binary. And -DDEBUG defines a pre-processor macro, DEBUG.
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_RELEASE} -g -DDEBUG")   


set(CMAKE_C_COMPILER /usr/bin/arm-linux-gnueabi-gcc)
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabi-g++)

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)