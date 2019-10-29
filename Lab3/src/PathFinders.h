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
class PathFinders {
public:
    void setMap(std::map<int,std::vector<float>>&);
    std::vector<int>(PathFinders::*PathAlgo)(int);
 std::vector<int>NBF(int src);
 std::vector<int>DP(int src);
    struct compare{
        bool operator()(const std::pair<std::vector<int>,float>&l,const std::pair<std::vector<int>,float>&r)
        {
            return l.second>r.second;
        }
    };

private:
     std::map<int,std::vector<float>>node_map;

};


#endif //SRC_PATHFINDERS_H
