//
// Created by jakeb on 9/3/2019.
//

#include "DataSetCreator.h"
//Creates a data set based on the taken size and randomizes the integers
std::vector<int> DataSetCreator::random(int size) {
     std::vector<int>array;
    srand((unsigned)time(0));
    for(int i=0;i<size;i++)
    {
        array.push_back(rand()%100);
    }
    return array;

}
//Creates a data set based on the taken size and puts the integers in reverse order
std::vector<int> DataSetCreator::reverse(int size) {
    std::vector<int>array=this->random(size);
    std::sort(array.rbegin(),array.rend());
    return array;
}
//Creates a data set based on the taken size and sorts 30% of the array
std::vector<int> DataSetCreator::partiallyRandom(int size) {
    std::vector<int>array=this->random(size);

    for(int i=0;i<array.size()*.3;i++) {

        if (array[i] > array[i + 1]) {
            std::swap(array[i], array[i + 1]);
        }
    }
    return array;
}
//Creates a vector with 20% unique data values, with reamining 80% being duplicates in random order
std::vector<int> DataSetCreator::TwentyPercentUnique(int size) {
    std::vector<int>array;
    int unique=size/5;
    srand((unsigned)time(0));
    for(int i=0;i<unique;i++)
    {
        array.push_back(rand()%size);
    }
    for(int i=0;i<(size-unique);i++)
    {
       int x=rand()%unique;
       array.push_back(array[x]);
    }
    return array;

}
//Takes a vector and creates an out file
void DataSetCreator::dataFile(std::vector<int> array,int a) {
    std::ofstream out;

        out.open("DataSet"+std::to_string(a));
        for(int i=0;i<array.size();i++)
        {
            int x=array[i];
            out<<x<<std::endl;
        }
        out.close();
}