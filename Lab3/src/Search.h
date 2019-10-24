//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCH_H
#define SEARCHING_SEARCH_H
#include <fstream>
#include "Algorithm.h"
#include <vector>
#include <iostream>
#include <sstream>
#include "PathFinders.h"
#include "FileLoader.h"
class Search: public Algorithm{
public:
virtual void  Load(std::string,std::string,std::string,int);
virtual void Execute(int,int);//Running switch statement
virtual void Display();
virtual void Stats(int algo);
virtual void Select(int);//Select active algorithm
virtual void Save(std::string,int,std::string);
virtual void Configure();
void Clear();
void load_Test_Nodes(std::string);
std::map<int,int>& get_Test_Nodes();
void printAverages();

private:
    std::vector<int>(*PathAlgo)(int)=nullptr;

};



#endif //SEARCHING_SEARCH_H
