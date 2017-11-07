cmake_minimum_required(VERSION 3.5)
project(ComputePi)

set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -pthread -g3 -O0 ${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES main.cpp compPi.cpp compPi.hpp)

add_executable(ComputePi ${SOURCE_FILES})

 
