cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(src
        Algorithm.h
        Search.cpp
        Search.h
        searching_Algos.cpp
        searching_Algos.h
        LinkedList.h
        AdjList.h
        AdjList.cpp
        AdjMatrix.cpp
        AdjList.h
        Tree.cpp
        Tree.h
        main.cpp)


