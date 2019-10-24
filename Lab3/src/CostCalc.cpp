//
// Created by jakeb on 10/23/2019.
//

#include "CostCalc.h"
float CostCalc::calcPathCost(const std::vector<int> &path,std::map<int,std::vector<float>>&node_map) {
        float cost=0;
        std::map<int,std::vector<float>>::iterator it;
        for(int i=1;i<path.size();i++)
        {
            float x1=node_map[path[i-1]][0];
            float y1=node_map[path[i-1]][1];
            float z1=node_map[path[i-1]][2];
            float x2=node_map[path[i]][0];
            float y2=node_map[path[i]][1];
            float z2=node_map[path[i]][2];
            float distance=(pow((x2-x1),2))+(pow((y2-y1),2))+(pow((z2-z1),2));
            cost+=distance;
        }
        return cost;

}