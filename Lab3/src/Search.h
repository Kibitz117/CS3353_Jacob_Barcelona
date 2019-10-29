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
#include "StructureHandler.h"
class Search: public Algorithm{
public:
virtual void  Load(std::string,int);
virtual void Execute(int);//Running switch statement
virtual void Display();
virtual void Stats(int algo);
virtual void Select(int);//Select active algorithm
virtual void Save(std::string,int,std::string);
virtual void Configure();


private:
    StructureHandler* s;
    MapHandler* map;
    PathFinders p;
    enum Algo{
        NBF=0,
        DP
    };

};



#endif //SEARCHING_SEARCH_H
