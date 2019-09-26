//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCH_H
#define SEARCHING_SEARCH_H
#include <fstream>
#include "Algorithm.h"
#include "searching_Algos.h"
#include "AdjList.h"
class Search: public Algorithm{
virtual void  Load(std::string);
virtual void Execute();//Running switch statement
virtual void Display();
virtual void Stats(int algo);
virtual void Select(int);//Select active algorithm
virtual void Save(std::string,int,std::string);
virtual void Configure();
void Clear();
};


#endif //SEARCHING_SEARCH_H
