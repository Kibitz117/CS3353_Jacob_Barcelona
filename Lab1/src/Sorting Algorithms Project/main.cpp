//
// Created by jakeb on 9/4/2019.
//
#include "Sort_Algos.h"
int main(){
    Sort algo;
    std::vector<int>array;
    algo.Load("C:\\Algorithms\\Lab1\\src\\Sorting Algorithms Project\\DataSet",array);
    algo.Display(array);
    //auto (Sort::)
    std::cout<<std::endl;
    algo.Display(array);

}