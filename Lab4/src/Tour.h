//
// Created by jakeb on 11/15/2019.
//

#ifndef SRC_TOUR_H
#define SRC_TOUR_H
#include <algorithm>
#include <vector>
#include "CostCalc.h"
class Tour {
public:
    Tour();
    std::vector<int>& getTour();
    void generateTour(std::vector<int>tour);
    float getFitness();
    void setProbability(int sum);
    void calcFitness(int src,std::map<int,std::vector<float>>node_map);
    float getCost();
    void setCost(float);
    void setTour(std::vector<int>&);
    void operator=(const Tour&);
    bool operator ==(const Tour&)const;
    void swap(int,int,std::map<int,std::vector<float>>node_map);


private:
    float cost;
    float fitness;
    std::vector<int> tour;
    float probability;


};


#endif //SRC_TOUR_H
//Tour will create our paths
//Tour handler will make a map or vector of pairs with vector and cost"Fitness"
//Fitness is 1/distance