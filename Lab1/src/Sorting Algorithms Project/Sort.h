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
virtual void Execute();
virtual void Display(std::vector<int>&);
virtual void Stats();
virtual void Select();
virtual void Save();
virtual void Configure();
private:
 void (*SortAlgo)(std::vector<int>);


};
#endif //SRC_SORT_H
