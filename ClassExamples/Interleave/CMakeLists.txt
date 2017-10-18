cmake_minimum_required(VERSION 3.5)
project(Assignment3)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra ${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp interleave.cpp interleave.hpp)

add_executable(Interleave ${SOURCE_FILES})

 
