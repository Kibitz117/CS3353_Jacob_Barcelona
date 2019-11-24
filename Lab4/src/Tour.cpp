//
// Created by jakeb on 11/15/2019.
//

#include "Tour.h"
Tour::Tour() {

}
//Generates a random path for tsp
void Tour::generateTour(std::vector<int>tour) {
std::random_shuffle(tour.begin(),tour.end());
this->tour=tour;
}
//Returns path for tsp
std::vector<int>& Tour::getTour() {
    return tour;
}
//Gets fitness rating for path
float Tour::getFitness()
{
    return fitness;
}
//Calculates fitness rating for path
void Tour::calcFitness(int src,std::map<int,std::vector<float>>node_map) {
    cost =CostCalc::calcPathCost(tour,node_map,src);
  fitness= 1/cost;

}
void Tour::setProbability(int sum) {
    probability=fitness/sum;
}
float Tour::getCost() {
    return cost;
}
void Tour::setCost(float cost) {
    this->cost=cost;
}
void Tour::operator=(const Tour &tour) {
    this->fitness=tour.fitness;
    this->tour=tour.tour;
    this->cost=tour.cost;
    this->probability=tour.probability;
}
bool Tour::operator==(const Tour &tour)const {

    if(this->cost==tour.cost&&this->tour==tour.tour)
    {
        return true;
    }
    return false;
}
void Tour::setTour(std::vector<int> &path) {
    this->tour=path;
}
void Tour::swap(int i, int x,std::map<int,std::vector<float>>node_map) {
    int temp=tour[i];
    tour[i]=tour[x];
    tour[x]=temp;
    calcFitness(1,node_map);
}