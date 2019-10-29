//
// Created by jakeb on 10/21/2019.
//

#include "PathFinders.h"
void PathFinders::setMap(std::map<int, std::vector<float>> &map) {
    node_map=map;
}
std::vector<int> PathFinders::NBF(int src) {

    //Make src and dest same node
    int dest=src;
    std::map<int,std::vector<float>>::iterator it=node_map.begin();
    //Map represented as vector to use next_permutation
    std::vector<int>path;
    //Iterate through map to  fill path
    while(it!=node_map.end())
    {
        it++;
        path.push_back(it->first);
    }
    //MAKE IT SO SRC NODE IS THE SAME EVERYTIME EG EVERY PATH STARTS WITH 1
    //Priority queue with least cost on top
    std::priority_queue<std::pair<std::vector<int>,float>,std::vector<std::pair<std::vector<int>,float>>,compare>priorityQueue;
    do{
        //push current permutation to priorityQueue
        float cost=CostCalc::calcPathCost(path,node_map);
        priorityQueue.push(make_pair(path,cost));
        //Keep looping until no more permutations exist
    }while(std::next_permutation(path.begin(),path.end()));
    std::vector<int>f_path=priorityQueue.top().first;
    for(int i=0;i<f_path.size();i++)
    {
        std::cout<<f_path[i]<<" ";
    }
    return priorityQueue.top().first;

}
//std::vector<int> PathFinders::NBF(int src) {
//    return std::vector<int>temp;
//}
