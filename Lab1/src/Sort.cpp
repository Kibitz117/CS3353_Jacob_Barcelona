//
// Created by jakeb on 9/4/2019.
//

#include "Sort.h"
//Loads the file into a vector to be used to sort or
void Sort::Load(std::string fileName) {
    std::fstream dataFile;
    dataFile.open(fileName);
    std::string line;
    int num;
    if(!dataFile) {
        std::cout << "No good";
    }
    while(std::getline(dataFile,line))
    {
        num=std::atoi(line.c_str());
        array.push_back(num);
    }

    dataFile.close();

}
//Executes function assigned to the SortAlgo pointer
void Sort::Execute() {
    //Start time of algorithm
    auto start_time = std::chrono::high_resolution_clock::now();
    (SortAlgo)(array);
    auto end_time = std::chrono::high_resolution_clock::now();
    time=std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();

}
//Displays the private data member array
void Sort::Display()
{   for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i]<<" ";
    }

}
//Clears the private data member array
void Sort::Clear() {
    this->array.clear();
}
//Prints the statistics on a SortAlgo (Speed,#items, algo name)
void Sort::Stats(int algo) {

    std::cout<<std::endl<<"Time for "<<array.size()<<" items"<<std::endl;
    std::cout << time << "ns" << std::endl;
    time=0;
}
//Selects the sorting algorithm based off the selected Algorithm
void Sort::Select(int i) {
    if(i==Bubble)
    {
        //Why isn't this line working?
        SortAlgo= &Sort_Algos::bubble_Sort;
        std::cout<<"Bubble Sort"<<std::endl;
        Execute();
    }
    else if(i==Insert)
    {
        SortAlgo= &Sort_Algos::insertion_Sort;
        std::cout<<"Insertion Sort"<<std::endl;
        Execute();
    }
    else if(i==Merge)
    {
        SortAlgo=&Sort_Algos::merge_Sort;
        std::cout<<"Merge Sort"<<std::endl;
        Execute();
    }
    else
    {
        std::cout<<"ERROR No Sort Selected"<<std::endl;
    }

}
//Saves the private data member array to an out file specified by the parameter
void Sort::Save(std::string path,int i,std::string filename) {
    std::ofstream out;
    path+=filename;
    if(i==Bubble)
    {
        path+="BubbleSort";
        out<<"Bubble Sort"<<std::endl;
        out<<filename<<std::endl;

    }
    else if(i==Insert)
    {
        path+="InsertionSort";
        out<<"Insertion Sort"<<std::endl;
        out<<filename<<std::endl;

    }
    else if(i==Merge)
    {
        path+="MergeSort";
        out<<"Merge Sort"<<std::endl;
        out<<filename<<std::endl;

    }
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