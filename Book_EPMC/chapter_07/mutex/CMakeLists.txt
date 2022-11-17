cmake_minimum_required(VERSION 3.5.1)
project(mutex)
add_executable(mutex mutex.cpp)

set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_CXX_FLAGS "--std=c++17")
target_link_libraries(mutex pthread)

set(CMAKE_CXX_COMPILER /usr/bin/arm-linux-gnueabi-g++)