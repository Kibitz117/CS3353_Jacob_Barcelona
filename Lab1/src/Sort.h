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
    Sort(){};
virtual void  Load(std::string);
virtual void Execute();//Running switch statement
virtual void Display();
virtual void Stats(int algo);
virtual void Select(int);//Select active algorithm
virtual void Save(std::string,int,std::string);
virtual void Configure();
void Clear();
private:
void(*SortAlgo)(std::vector<int>&)=nullptr;
 std::vector<int>array;
 float time;
 enum SORTING_ALGO{
     Bubble=0,
     Insert,
     Merge,
     END
 };


};
#endif //SRC_SORT_H
