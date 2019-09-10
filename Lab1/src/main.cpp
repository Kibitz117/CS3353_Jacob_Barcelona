//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
int main(){
    Sort algo;
    //Loop through these array
    std::string filetypes[4]{"PartiallyRandom","Random","Reverse","Twenty%"};
    std::string num_Data[4]{"(10)","(1000)","(10,000)","(100,000)"};

    //Algorithms
    for(int i=0;i<3;i++)
    {
        //File types
        for(int x=0;x<4;x++)
        {
            algo.Load("DataFiles/"+filetypes[x]+num_Data[3]);
            std::cout<<filetypes[x]<<std::endl;
            algo.Stats(i);
            algo.Clear();
            std::cout<<std::endl<<std::endl;
        }
    }
//See if it can be more OOP
//Save off statistics
//Time in execute
//Loop through all number of elements
//Put Sorting Algorithm Project in src

}