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
Tour TabuSearch::getBestSwap(Tour curr_best) {
    Tour curr=curr_best;
    std::vector<Tour>neighborhood;
    float total_fitness;
    //Add every possible tour to vector and "randomly" select one
    for(int i=1;i<=path.size();i++)
    {
        for(int x=i+1;x<path.size();x++)
        {
            curr.swap(i,x,node_map);

            neighborhood.push_back(curr);
            double score=curr.getFitness();
            total_fitness+=score;
            if(score>curr_best.getFitness()&&!has(curr))
            {
                curr_best=curr;
            }
        }

    }
    for(int i=0;i<neighborhood.size();i++)
    {
        neighborhood[i].setProbability(total_fitness);
    }
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = total_fitness - 0;
    float r = random * diff;
    float randNum= 0 + r;
    int count=0;
    while(randNum>0)
    {
        randNum-=neighborhood[count].getFitness();
        count++;
    }
    if(has(neighborhood[count-1])||neighborhood[count-1].getCost()-2<curr.getCost())
    {
        return curr_best;
    }
    return neighborhood[count-1];

}
//Tour TabuSearch::getBestRotate(Tour curr_best) {
//    Tour curr=curr_best;
//    std::vector<int>temp=curr_best.getTour();
//    std::vector<Tour>neighborhood;
//
//    for(int i=0;i<curr_best.getTour().size();i++)
//    {
//        int to_rotate=curr_best.getTour()[i];
//        for(int z=0;z<curr_best.getTour().size();z++)
//        {
//            curr.getTour()[z+1]=temp[z];
//        }
//        if(curr.getCost()<curr_best.getCost())
//        {
//            curr_best=curr;
//        }
//    }
//    curr_best.getTour()[0]=to_rotate;
//    curr_best.calcFitness(1,node_map);
//
//}
void TabuSearch::Run(int num_times) {
    //Getting tours that don't exist
    Tour best;
    best.generateTour(path);
    best.calcFitness(1,node_map);
    abs_best=best;
    tabuList.push_back(best);
    int run=0;
    while(run<num_times)
    {
        tabuList.clear();
        best=getBestSwap(best);
        if(best.getCost()<abs_best.getCost()&&!(best.getTour().empty()))
        {
            abs_best=best;
        }
        tabuList.push_back(best);
        //Add roulette wheel/ random chance
        if(tabuList.size()>listSize)
        {
            tabuList.erase(tabuList.begin());
        }
        run++;
        for(int i=0;i<abs_best.getTour().size();i++)
        {
            std::cout<<abs_best.getTour()[i]<<" ";
        }
        std::cout<<std::endl<<abs_best.getCost();

    }
    for(int i=0;i<abs_best.getTour().size();i++)
    {
        std::cout<<abs_best.getTour()[i]<<" ";
    }
    std::cout<<std::endl<<abs_best.getCost();
}