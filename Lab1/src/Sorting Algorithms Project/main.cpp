//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
int main(){
    Sort algo;
    algo.Load("C:\\Algorithms\\Lab1\\src\\Sorting Algorithms Project\\DataFiles\\PartiallyRandom(10,000)");
    //Loop through these arrays
    std::string filetypes[4]{"PartiallyRandom","Random","Reverse","Twenty%"};
    std::string num_Data[4]{"(10)","(1000)","(1,0000)","(100,000)"};
    algo.Select(1);
    algo.Display();
//algo.Stats(1);
//Figure out how to loop through files/put in vectors
//Do Merge Sort
//See if it can be more OOP



}