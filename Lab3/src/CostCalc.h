//
// Created by jakeb on 10/23/2019.
//

#ifndef SRC_COSTCALC_H
#define SRC_COSTCALC_H

#include <map>
#include <vector>
#include <cmath>
class CostCalc {
public:
static float calcPathCost(const std::vector<int>&,std::map<int,std::vector<float>>&,int src);
static float distance(int src,int dest,std::map<int,std::vector<float>>&node_map);
};


#endif //SRC_COSTCALC_H
