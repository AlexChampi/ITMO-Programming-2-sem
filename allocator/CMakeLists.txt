cmake_minimum_required(VERSION 3.22)
project(allocator)

set(CMAKE_CXX_STANDARD 20)

add_executable(allocator main.cpp Allocator.cpp Pool.cpp)
