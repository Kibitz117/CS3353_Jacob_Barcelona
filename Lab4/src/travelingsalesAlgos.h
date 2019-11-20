//
// Created by jakeb on 11/13/2019.
//

#ifndef SRC_TRAVELINGSALESALGOS_H
#define SRC_TRAVELINGSALESALGOS_H

#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include "CostCalc.h"
#include <iostream>
#include "StructureHandler.h"
class travelingsalesAlgos {
public:
    std::vector<int>(travelingsalesAlgos::*PathAlgo)(int);


private:
    std::map<int,std::vector<float>>node_map;
};


#endif //SRC_TRAVELINGSALESALGOS_H
