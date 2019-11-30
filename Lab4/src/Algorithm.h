//
// Created by jakeb on 9/4/2019.
//

#ifndef SRC_ALGORITHM_H
#define SRC_ALGORITHM_H

#include <vector>
#include <iostream>
#include<algorithm>
#include <chrono>
class Algorithm{
public:
    virtual void Load(std::string,int)=0;
    virtual void Execute(int)=0;
    virtual void Display()=0;
    virtual void Stats(int)=0;
    virtual void Select(int)=0;
    virtual void Save(std::string,int,std::string)=0;
    virtual void Configure(int)=0;

};
#endif //SRC_ALGORITHM_H
