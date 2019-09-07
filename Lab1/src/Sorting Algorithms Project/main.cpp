//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
int main(){
    Sort algo;
    std::vector<int>array;
    algo.Load("DataFiles/PartiallyRandom(10)",array);
    algo.Display(array);
    //auto (Sort::)
    std::cout<<std::endl;
    algo.Display(array);

}