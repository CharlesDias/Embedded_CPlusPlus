cmake_minimum_required(VERSION 3.5.1)
project(shmem)
add_executable(shmem shmem.cpp)
target_link_libraries(shmem rt)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

SET(CMAKE_CXX_FLAGS "--std=c++17")
set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabi-g++)