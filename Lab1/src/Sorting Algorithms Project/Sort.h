//
// Created by jakeb on 9/4/2019.
//

#ifndef SRC_SORT_H
#define SRC_SORT_H
#include <fstream>
//Circular inclusion
#include "Algorithm.h"
class Sort:public Algorithm{
public:
virtual void  Load(std::string,std::vector<int>&);
virtual void Execute(int);//Running switch statement
virtual void Display(std::vector<int>&);
virtual void Stats();
virtual void Select(void*);//Select active algorithm
virtual void Save(std::string,std::vector<int>);
virtual void Configure();
//virtual void sort_Array();
private:
 void (*SortAlgo)(std::vector<int>);
 enum SORTING_ALGO{
     Bubble=0,
     Merge,
     Insert,
     END
 };


};
#endif //SRC_SORT_H
