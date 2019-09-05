//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
//Loads the file into a vector to be used to sort or
void Sort::Load(std::string fileName,std::vector<int>&array) {
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
void Sort::Execute(void*fptr) {
    //This would dereference the function pointer correct?
    this.*(fptr)();
}
void Sort::Display(std::vector<int>&array) {
    for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i]<<" ";
    }
}
void Sort::Stats() {

}
//Is something like this correct? Also how would I contunially switch between algos?
void Sort::Select(int i) {
    if(i==Bubble)
    {
        //How to do this without circular inclusion?
        //this->SortAlgo=&Sort_Algos::bubble_sort;
        Execute(this->SortAlgo);
    }
    else if(i==Insert)
    {

    }
    else
    {

    }

}
void Sort::Save(std::string path,std::vector<int>array) {
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