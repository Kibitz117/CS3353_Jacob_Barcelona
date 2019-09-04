//
// Created by jakeb on 9/4/2019.
//

#ifndef SRC_SORT_H
#define SRC_SORT_H

#include "Algorithm.h"
#include <fstream>
class Sort:public Algorithm{
public:
virtual std::vector<int> Load(std::string);
virtual void Execute();
virtual void Display();
virtual void Stats();
virtual void Select();
virtual void Save();
virtual void Configure();
private:

};
#endif //SRC_SORT_H
