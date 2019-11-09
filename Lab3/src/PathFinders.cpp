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
    cost= priorityQueue.top().second;
    return priorityQueue.top().first;

}
std::vector<int> PathFinders::Dynamic(int src) {
    int n=node_map.size();
    std::vector<int>path;
    std::vector<int>middle;
   // this->makeDistances(n);
   path.push_back(src);
    for(int i=2;i<=n;i++)
    {
        middle.push_back(i);
    }
    float distance=this->DP(src,src,middle,path);
    path.push_back(src);
    cost=distance;
    return path;

}
float PathFinders::DP(int src,int dest,std::vector<int>middle,std::vector<int>&path) {

    if(middle.empty())
    {
        return CostCalc::distance(src,dest,node_map);
    }
    else{
        std::vector<float>sum;
        for(int i=0;i<middle.size();i++)
        {
            std::vector<int>temp=middle;
            temp.erase(temp.begin()+i);
            float min=1000;
            int minindex=0;
            for(int a=2;a<=node_map.size();a++)
            {
                if(CostCalc::distance(src,a,node_map)<min)
                {
                    min=CostCalc::distance(src,a,node_map);
                    minindex=a;
                }
            }
            if(!(std::count(path.begin(),path.end(),minindex)))
            {
                path.push_back(minindex);
            }
//            if(path.size()==node_map.size())
//            {
//                middle.clear();
//                path.erase(path.begin());
//                float cost=CostCalc::calcPathCost(path,node_map,1);
//                return cost;
//            }

            sum.push_back(CostCalc::distance(src,middle[i],node_map)+DP(middle[i],dest,temp,path));
        }
        float min=1000;
        for(int i=0;i<sum.size();i++)
        {
            if(sum[i]<min){
                min=sum[i];
            }
        }

        return min;
    }

}
//void PathFinders::makeDistances(int n) {
//    for(int i=0;i<n;i++)
//    {
//        for(int z=0;z<n;z++)
//        {
//            dist[i][z]=CostCalc::distance((i+1),(z+1),node_map);
//        }
//    }
//}
