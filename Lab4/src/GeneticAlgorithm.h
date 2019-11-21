//
// Created by jakeb on 11/14/2019.
//

#ifndef SRC_GENETICALGORITHM_H
#define SRC_GENETICALGORITHM_H

#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include "CostCalc.h"
#include <iostream>
#include "StructureHandler.h"
#include "Tour.h"
#include <cstdlib>
#include <ctime>
class GeneticAlgorithm {
    //Elitism at first
    //STORE GLOBAL BESTS
    //Look at costs
    //Run more extensively
    //Look at better algos

public:
    GeneticAlgorithm(int src,int size,std::vector<int>path,std::map<int,std::vector<float>>&node_map);
    //Execute(int src,node_map/vector path,int generations)
    //Selection
        void rouletteWheel(Tour&);
        //Top two
        void elitism(Tour&);
        //Tournament
        Tour tournament();
    //Crossover
        //One-point
        Tour one_Point_Crossover(Tour&,Tour&);
        //OX1
        //Multi-point
        Tour multi_Point_Crossover(Tour&,Tour&);
    //Mutation
        //Bit flip for binary encoded
        void swap_Mutation(Tour&,Tour&);
        //Swap mutation two positions

        //Evolve population
        void evolve();
private:
    void setMap(std::map<int,std::vector<float>>&node_map);
    std::vector<Tour>population;
    Tour global_best;
   std::map<int,std::vector<float>>node_map;
   int src;

};


#endif //SRC_GENETICALGORITHM_H
