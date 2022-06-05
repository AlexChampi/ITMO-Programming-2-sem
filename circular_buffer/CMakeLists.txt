cmake_minimum_required(VERSION 3.22)
project(circular_buffer)

set(CMAKE_CXX_STANDARD 20)

add_executable(circular_buffer src/main.cpp include/iterator.h include/circular_buffer.h include/algorithms.h)
#include(GoogleTest)
#gtest_discover_tests(circular_buffer.h)
