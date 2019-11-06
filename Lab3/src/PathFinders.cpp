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
    it++;
    while(it!=node_map.end())
    {
        path.push_back(it->first);
        it++;
    }
    //MAKE IT SO SRC NODE IS THE SAME EVERYTIME EG EVERY PATH STARTS WITH 1
    //Priority queue with least cost on top
    std::priority_queue<std::pair<std::vector<int>,float>,std::vector<std::pair<std::vector<int>,float>>,compare>priorityQueue;
    do{
        //push current permutation to priorityQueue
        float cost=CostCalc::calcPathCost(path,node_map,src);
        priorityQueue.push(make_pair(path,cost));
        //Keep looping until no more permutations exist
    }while(std::next_permutation(path.begin(),path.end()));
    std::vector<int>f_path=priorityQueue.top().first;
    std::cout<<src<<" ";
    for(int i=0;i<f_path.size();i++)
    {
        std::cout<<f_path[i]<<" ";
    }
    std::cout<<src<<std::endl;
    return priorityQueue.top().first;

}

float PathFinders::DP(int mask, int src) {
    if(src==1)
    {
        //Initalizes the distances between all nodes
        this->makeDistances();
        //Initializes matrix setting all to negative 1
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                dp[i][j] = -1;
            }
        }
    }
    //Checks if visited all nodes
    if(mask==VISITED_ALL){
        return dist[src][0];
    }
    //Checks if node has been visited
    if(dp[mask][src]!=-1){
        return dp[mask][src];
    }

    //Now from current node, we will try to go to every other node and take the min ans
    float ans = INT_MAX;

    //Visit all the unvisited cities and take the best route
    for(int city=0;city<n;city++) {

        if ((mask & (1 << city)) == 0) {
            float newAns = dist[src][city] + DP(mask | (1 << city), city);
            if (newAns < ans) {
                ans = newAns;
                //std::cout<<src<<" ";
            }
        }

    }
    return dp[mask][src] = ans;
}
std::vector<int> PathFinders::Dynamic(int src) {
    std::vector<int>path;
    float distance=this->DP(1,src);
    std::cout<<"Shortest path is"<<distance<<std::endl;
    return path;

}
void PathFinders::makeDistances() {
    for(int i=0;i<n;i++)
    {
        for(int z=0;z<n;z++)
        {
            dist[i][z]=CostCalc::distance((i+1),(z+1),node_map);
        }
    }
}
