//
// Created by jakeb on 9/3/2019.
//
#include "DataSetCreator.h"
int main()
{
    DataSetCreator collect;
    std::vector<int> array;
    array=collect.random(10);
    collect.dataFile(array,1);
    array=collect.random(1000);
    collect.dataFile(array,2);
    array=collect.random(10000);
    collect.dataFile(array,3);
    array=collect.random(100000);
    collect.dataFile(array,4);

    array=collect.reverse(10);
    collect.dataFile(array,5);
    array=collect.reverse(1000);
    collect.dataFile(array,6);
    array=collect.reverse(10000);
    collect.dataFile(array,7);
    array=collect.reverse(100000);
    collect.dataFile(array,8);

    array=collect.TwentyPercentUnique(10);
    collect.dataFile(array,9);
    array=collect.TwentyPercentUnique(1000);
    collect.dataFile(array,10);
    array=collect.TwentyPercentUnique(100000);
    collect.dataFile(array,11);
    array=collect.TwentyPercentUnique(100000);
    collect.dataFile(array,12);

    array=collect.partiallyRandom(10);
    collect.dataFile(array,13);
    array=collect.partiallyRandom(1000);
    collect.dataFile(array,14);
    array=collect.partiallyRandom(10000);
    collect.dataFile(array,15);
    array=collect.partiallyRandom(100000);
    collect.dataFile(array,16);
}



