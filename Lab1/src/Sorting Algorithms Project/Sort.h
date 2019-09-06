//
// Created by jakeb on 9/4/2019.
//

#ifndef SRC_SORT_H
#define SRC_SORT_H
#include <fstream>
#include "Sort_Algos.h"
#include "Algorithm.h"
class Sort:public Algorithm{
public:
virtual void  Load(std::string);
virtual void Execute();//Running switch statement
virtual void Display();
virtual void Stats();
virtual void Select(int);//Select active algorithm
virtual void Save(std::string);
virtual void Configure();
private:
 void(*SortAlgo)(std::vector<int> &data);
 std::vector<int>array;
 enum SORTING_ALGO{
     Bubble=0,
     Merge,
     Insert,
     END
 };


};
#endif //SRC_SORT_H
