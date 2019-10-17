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
void load_Test_Nodes(std::string);
std::map<int,int>& get_Test_Nodes();
void printAverages();

private:
    std::map<std::pair<int,int>,double>weight_values;
    std::map<int,std::vector<int>>node_positions;
    std::map<int,int>test_Nodes;
    Graph* list;
    float time;
    std::vector<int>path;
    static float avg_time;
    static int avg_path_nodes;
    static int avg_nodes_explored;
    std::vector<float>times;
    std::vector<int>avg_path;
    std::vector<int>avg_nodes;
    static double avg_distance;
    static double avg_cost;
    static int count;
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
