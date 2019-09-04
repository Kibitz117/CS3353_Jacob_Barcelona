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
void Sort::Execute() {

}
void Sort::Display(std::vector<int>array) {
    for(int i=0;i<array.size();i++)
    {
        std::cout<<array[i]+" ";
    }
}
void Sort::Stats() {

}
void Sort::Select() {

}
void Sort::Save() {

}
void Sort::Configure() {

}