//
// Created by jakeb on 10/23/2019.
//

#include "CostCalc.h"
float CostCalc::calcPathCost(const std::vector<int> &path,std::map<int,std::vector<float>>&node_map,int src) {
        float cost=0;
        std::map<int,std::vector<float>>::iterator it;
    float x1=node_map[src][0];
    float y1=node_map[src][1];
    float z1=node_map[src][2];
    float x2=node_map[path[0]][0];
    float y2=node_map[path[0]][1];
    float z2=node_map[path[0]][2];
    float distance=sqrt(pow((x2-x1),2))+(pow((y2-y1),2))+(pow((z2-z1),2));
    cost+=distance;
        for(int i=1;i<path.size();i++)
        {
            x1=node_map[path[i-1]][0];
            y1=node_map[path[i-1]][1];
            z1=node_map[path[i-1]][2];
            x2=node_map[path[i]][0];
            y2=node_map[path[i]][1];
            z2=node_map[path[i]][2];
            distance=sqrt(pow((x2-x1),2))+(pow((y2-y1),2))+(pow((z2-z1),2));
            cost+=distance;
        }
    x1=node_map[path[path.size()-1]][0];
    y1=node_map[path[path.size()-1]][1];
    z1=node_map[path[path.size()-1]][2];
    x2=node_map[src][0];
    y2=node_map[src][1];
    z2=node_map[src][2];
     distance=sqrt(pow((x2-x1),2))+(pow((y2-y1),2))+(pow((z2-z1),2));
    cost+=distance;
        return cost;

}