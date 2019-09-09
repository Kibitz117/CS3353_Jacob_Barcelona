//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
int main(){
    Sort algo;
    algo.Load("DataFiles/PartiallyRandom(10)");
//    auto start_time = std::chrono::high_resolution_clock::now();
//    algo.Execute();
//    //End time of algorithm
//    auto end_time = std::chrono::high_resolution_clock::now();
//    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count() << "ns" << std::endl;
    algo.Select(1);
    algo.Display();
    //auto (Sort::)

}