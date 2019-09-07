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
    virtual void Load(std::string)=0;
    virtual void Execute()=0;
    virtual void Display()=0;
    virtual void Stats()=0;
    virtual void Select(int)=0;
    virtual void Save(std::string)=0;
    virtual void Configure()=0;

};
#endif //SRC_ALGORITHM_H
