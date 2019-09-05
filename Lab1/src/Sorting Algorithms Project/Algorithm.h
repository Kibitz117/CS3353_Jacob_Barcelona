//
// Created by jakeb on 9/4/2019.
//

#ifndef SRC_ALGORITHM_H
#define SRC_ALGORITHM_H

#include <vector>
#include <iostream>
#include<algorithm>
class Algorithm{
public:
virtual void Load(std::string,std::vector<int>&)=0;
    virtual void Execute()=0;
    virtual void Display(std::vector<int>&)=0;
    virtual void Stats()=0;
    virtual void Select()=0;
    virtual void Save(std::string,std::vector<int>)=0;
    virtual void Configure()=0;

};
#endif //SRC_ALGORITHM_H
