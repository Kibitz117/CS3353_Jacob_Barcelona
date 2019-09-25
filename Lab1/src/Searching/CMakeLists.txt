cmake_minimum_required(VERSION 3.14)
project(Searching)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Searching
        "Algorithm(2).h"
        Search.cpp
        Search.h
        searching_Algos.cpp
        searching_Algos.h)
