//
// Created by jakeb on 11/21/2019.
//

#ifndef SRC_TABUSEARCH_H
#define SRC_TABUSEARCH_H

#include "TSPInterface.h"
#include "Tour.h"
#include <vector>
class TabuSearch:public TSPInterface {
    //initializes tabu list
    //Set some solution to current best
public:
    void Run(int);
    TabuSearch(int src,int size,std::vector<int>path,std::map<int,std::vector<float>>&node_map);
    void resetList();
    void Execute(int num_times);
    bool has(Tour);
    Tour getBestNearby(Tour);

private:
    std::vector<int>path;
    std::vector<Tour>solutions;
    std::vector<Tour>tabuList;
    int listSize;
    std::map<int,std::vector<float>>node_map;
    
};


#endif //SRC_TABUSEARCH_H
