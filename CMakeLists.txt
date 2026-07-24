cmake_minimum_required(VERSION 3.30)
project(emulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(emulator src/main.cpp
        src/MMU.cpp
        include/MMU.h)
target_include_directories(emulator PRIVATE include)