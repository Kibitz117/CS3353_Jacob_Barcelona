cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp
        FileLoader.cpp
        FileLoader.h
        PathFinders.cpp
        PathFinders.h
        StructureHandler.h
        MapHandler.h
        MapHandler.cpp
        Search.h
        Algorithm.h
        StructureFactory.h
        StructureFactory.cpp
        Search.cpp
        CostCalc.cpp
        CostCalc.h
        )