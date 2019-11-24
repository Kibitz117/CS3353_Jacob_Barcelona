//
// Created by jakeb on 11/21/2019.
//

#include <iostream>
#include "TabuSearch.h"
TabuSearch::TabuSearch(int src,int size,std::vector<int>path,std::map<int,std::vector<float>>&node_map) {
 this->path=path;
 this->node_map=node_map;
 listSize=size;
}
bool TabuSearch::has(Tour t) {
    if(std::find(tabuList.begin(),tabuList.end(),t)!=tabuList.end())
    {
        return true;
    }
    return false;
}
//Solution that finds the best nearby solution by swaping two elements
Tour TabuSearch::getBestNearby(Tour curr_best) {
    Tour curr=curr_best;
    for(int i=1;i<=path.size();i++)
    {
        for(int x=i+1;x<path.size();x++)
        {
            curr.swap(i,x,node_map);
            double score=curr.getFitness();
            if(score>curr_best.getFitness()&&!has(curr))
            {
                curr_best=curr;
            }
        }
    }
    return curr_best;
}
void TabuSearch::Execute(int num_times) {
    tabuList.clear();
    Tour best;
    best.generateTour(path);
    best.calcFitness(1,node_map);
    tabuList.push_back(best);
    int run=0;
    while(run<num_times)
    {
        best=getBestNearby(best);
        tabuList.push_back(best);
        if(tabuList.size()>listSize)
        {
            tabuList.erase(tabuList.begin());
        }
        run++;
    }
    for(int i=0;i<best.getTour().size();i++)
    {
        std::cout<<best.getTour()[i]<<" ";
    }
    std::cout<<std::endl<<best.getCost();
}