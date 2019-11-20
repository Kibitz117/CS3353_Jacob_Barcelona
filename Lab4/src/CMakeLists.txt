cmake_minimum_required(VERSION 3.14)
project(src)

set(CMAKE_CXX_STANDARD 14)

add_executable(src main.cpp
        Algorithm.h
        CostCalc.h
        CostCalc.cpp
        FileLoader.h
        FileLoader.cpp
        Search.h
        Search.cpp
        MapHandler.h
        MapHandler.cpp
        StructureFactory.h
        StructureFactory.cpp
        StructureHandler.h
        travelingsalesAlgos.h
        travelingsalesAlgos.cpp
        GeneticAlgorithm.h
        GeneticAlgorithm.cpp
        Tour.h
        Tour.cpp)