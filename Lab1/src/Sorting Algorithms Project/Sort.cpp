//
// Created by jakeb on 9/4/2019.
//
#include <chrono>
#include "Sort.h"
//Loads the file into a vector to be used to sort or
void Sort::Load(std::string fileName) {
    std::fstream dataFile;
    dataFile.open(fileName);
    std::string line;
    int num;
    if(!dataFile)
    {
        std::cout<<"No good";
    }
    while(std::getline(dataFile,line))
    {
        num=std::atoi(line.c_str());
        array.push_back(num);
    }
    dataFile.close();

}
void Sort::Execute() {
    (SortAlgo)(array);
}
void Sort::Display()
{   for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i]<<" ";
    }
}
void Sort::Stats(int algo) {
    switch(algo)
    {
        case Bubble:std::cout<<"Bubble Sort";
        case Merge:std::cout<<"Merge Sort";
        case Insert:std::cout<<"Insertion Sort";
    }
    auto start_time = std::chrono::high_resolution_clock::now();




}
//Selects the sorting algorithm based off the selected Algorithm
void Sort::Select(int i) {
    if(i==Bubble)
    {
        //Why isn't this line working?
        SortAlgo= &Sort_Algos::bubble_Sort;
        Execute();
    }
    else if(i==Insert)
    {

    }
    else
    {

    }

}
void Sort::Save(std::string path) {
    std::ofstream out;
    out.open(path);
    for(int i=0;i<array.size();i++)
    {
        int x=array[i];
        out<<x<<std::endl;
    }
    out.close();
}
void Sort::Configure() {

}