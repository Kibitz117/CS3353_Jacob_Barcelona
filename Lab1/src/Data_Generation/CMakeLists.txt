cmake_minimum_required(VERSION 3.14)
project(Data_Generation)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Data_Generation
        DataSetCreator.cpp
        DataSetCreator.h
        main.cpp)
