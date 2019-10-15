//
// Created by jakeb on 9/27/2019.
//
#include "Search.h"
#include "AdjList.h"
#include <iostream>
int main(int argc,char*argv[])
{
    Search s;
    //AdjList or Matrix
    for(int i=0;i<2;i++)
    {
        s.Load("C:\\Algorithms\\Lab2\\src\\cmake-build-debug\\graph.txt","C:\\Algorithms\\Lab2\\src\\cmake-build-debug\\weights.txt","C:\\Algorithms\\Lab2\\src\\cmake-build-debug\\positions.txt",i);
        //Loop through each algo
        for(int a=0;a<5;a++)
        {
            s.Select(a);
            int src=atoi(argv[1]);
            int dest=atoi(argv[2]);
            s.Execute(src,dest);
            s.Stats(a);
        }
    }
}