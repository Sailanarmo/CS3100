cmake_minimum_required(VERSION 3.5)
project(Assignment2)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra ${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp compute-e.hpp compute-e.cpp compute-fib.cpp compute-fib.hpp compute-pi.cpp compute-pi.hpp)

add_executable(Assign2 ${SOURCE_FILES})

 
