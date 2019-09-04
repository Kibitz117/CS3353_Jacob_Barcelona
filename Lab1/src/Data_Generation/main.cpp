//
// Created by jakeb on 9/3/2019.
//
#include <iostream>
#include "DataSetCreator.h"
int main()
{
    DataSetCreator collect;
    int size=100;
    std::vector<int> array;
    //array=collect.random(size);
    array=collect.TwentyPercentUnique(100);
    for(int i=0;i<size;i++)
    {
        std::cout<<array[i]<<" ";
    }
    collect.dataFile(array);
}
