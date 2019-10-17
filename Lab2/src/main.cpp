//
// Created by jakeb on 9/27/2019.
//
#include "Search.h"
int main(int argc,char*argv[])
{
    Search s;


    //AdjList or Matrix
    for(int z=0;z<2;z++) {

        for(int i=0;i<2;i++)
        {
            if(z==0)
            s.Load("src/cmake-build-debug/largeGraph.txt","src/cmake-build-debug/largeWeights.txt","src/cmake-build-debug/largePositions.txt",i);
            else
                s.Load("src/cmake-build-debug/graph.txt","src/cmake-build-debug/positions.txt","src/cmake-build-debug/weights.txt",i);
            //Loop through each algo
            for(int a=0;a<6;a++)
            {
                s.Select(a);
                int src=atoi(argv[1]);
                int dest=atoi(argv[2]);
                s.Execute(src,dest);
                s.Stats(a);
            }
        }
    }




}