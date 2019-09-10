cmake_minimum_required(VERSION 3.14)
project(Sorting_Algorithms_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(.
        cmake-build-debug/DataFiles)

add_executable(Sorting_Algorithms_Project
        Algorithm.h
        main.cpp
        Sort.cpp
        Sort.h
        Sort_Algos.cpp
        Sort.h
        )
