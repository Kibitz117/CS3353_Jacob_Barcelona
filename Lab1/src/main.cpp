//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
int main(){
    Sort algo;
    //Loop through these array
    std::string filetypes[4]{"PartiallyRandom","Random","Reverse","Twenty%"};
    std::string num_Data[4]{"(10)","(1000)","(10,000)","(100,000)"};
    int files=0;
    std::string path="";
    //Algorithms
    for(int i=0;i<3;i++)
    {
        //File types
        for(int x=0;x<4;x++)
        {
            for(int a=0;a<4;a++)
            {
                files++;
                algo.Load("DataFiles/"+filetypes[x]+num_Data[a]);
                algo.Select(i);
                algo.Stats(i);
                algo.Save("Sorted",i,filetypes[x]+num_Data[a]);
                algo.Clear();
            }

        }
    }
//See if it can be more OOP
//Save off statistics
//Time in execute

}