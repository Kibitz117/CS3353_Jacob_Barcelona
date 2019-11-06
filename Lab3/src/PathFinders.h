//
// Created by jakeb on 10/21/2019.
//

#ifndef SRC_PATHFINDERS_H
#define SRC_PATHFINDERS_H

#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include "CostCalc.h"
#include <iostream>
#include "StructureHandler.h"
#define INT_MAX 999999
class PathFinders {
public:
    void setMap(std::map<int,std::vector<float>>&);
    std::vector<int>(PathFinders::*PathAlgo)(int);
 std::vector<int>NBF(int src);
 std::vector<int>Dynamic(int src);

private:
    void makeDistances();
    float DP(int mask,int src);
     std::map<int,std::vector<float>>node_map;
    int n=4;
    int VISITED_ALL = (1<<n) -1;
    float dist[4][4];
    float dp[16][4];
    std::vector<float>cities;
    struct compare{
        bool operator()(const std::pair<std::vector<int>,float>&l,const std::pair<std::vector<int>,float>&r)
        {
            return l.second>r.second;
        }
    };


};


#endif //SRC_PATHFINDERS_H
