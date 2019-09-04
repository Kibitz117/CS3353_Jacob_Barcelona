//
// Created by jakeb on 9/4/2019.
//
#include "Sort.h"
//Loads the file into a vector to be used to sort or
std::vector<int> Sort::Load(std::string fileName) {
    std::fstream dataFile;
    std::vector<int>array;
    dataFile.open(fileName);
    std::string line;
    int num;
    while(dataFile.good())
    {
        std::getline(dataFile,line);
        num=std::atoi(line.c_str());
        array.push_back(num);
    }
    dataFile.close();
    for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i];
    }
    return array;
}
void Sort::Execute() {

}
void Sort::Display() {

}
void Sort::Stats() {

}
void Sort::Select() {

}
void Sort::Save() {

}
void Sort::Configure() {

}