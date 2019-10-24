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
#include "CostCalc.cpp"
class PathFinders {
public:
std::vector<int>NBF(int src);
std::vector<int>DP();
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
