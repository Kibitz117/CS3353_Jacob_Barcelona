//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCH_H
#define SEARCHING_SEARCH_H
#include <fstream>
#include "Algorithm.h"
#include "AdjList.h"
#include <vector>
#include <iostream>
#include "Graph.h"
#include "AdjMatrix.h"
#include <sstream>
#include "searching_Algos.h"
class Search: public Algorithm{
public:
virtual void  Load(std::string,std::string,std::string,int);
virtual void Execute(int,int);//Running switch statement
virtual void Display();
virtual void Stats(int algo);
virtual void Select(int);//Select active algorithm
virtual void Save(std::string,int,std::string);
virtual void Configure();
void Clear();
private:
    std::map<std::pair<int,int>,double>weight_values;
    std::map<int,std::vector<int>>node_positions;
    Graph* list;
    float time;
    std::vector<int>path;
    std::vector<int>(*SearchAlgo)(int,int,Graph* g,std::map<std::pair<int,int>,double>&,std::map<int,std::vector<int>>&)=nullptr;
    enum SEARCHING_ALGO{
        DFS_ITER=0,
        DFS_RECUR,
        BFS_ITER,
        BFS_RECUR,
        DJKSTRA,
        A_STAR,
        END
    };
};


#endif //SEARCHING_SEARCH_H
