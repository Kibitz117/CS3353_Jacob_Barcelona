//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCH_H
#define SEARCHING_SEARCH_H
#include <fstream>
#include "Algorithm.h"
#include "searching_Algos.h"
#include "AdjList.h"
#include <vector>
#include <iostream>
#include "Graph.h"
#include "AdjMatrix.h"
#include <sstream>
class Search: public Algorithm{
public:
virtual void  Load(std::string,std::string,std::string);
virtual void Execute();//Running switch statement
virtual void Display();
virtual void Stats(int algo);
virtual void Select(int);//Select active algorithm
virtual void Save(std::string,int,std::string);
virtual void Configure();
void Clear();
private:
    Graph* list;
    int src;
    int dest;
    float time;
    void(*SearchAlgo)(int,int,Graph* g)=nullptr;
    enum SEARCHING_ALGO{
        DFS_ITER=0,
        DFS_RECUR,
        BFS_ITER,
        BFS_RECUR,
        END
    };
};


#endif //SEARCHING_SEARCH_H
