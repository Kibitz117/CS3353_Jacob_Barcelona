//
// Created by jakeb on 10/23/2019.
//
#include "Search.h"
void Search::Load(std::string path, int structure) {
    FileLoader loader;
s=loader.load("C:\\Algorithms\\Lab3\\src\\cmake-build-debug\\positions.txt",structure);
if(structure==0)
{
    map= dynamic_cast<MapHandler *>(s);

}p.setMap(map->getMap());}
void Search::Execute(int src,int mask) {
   (p.*(p.PathAlgo))(src);

}
void Search::Stats(int algo) {

}
void Search::Save(std::string, int, std::string) {

}
void Search::Display() {

}
void Search::Configure() {

}
void Search::Select(int i) {

    if(i==NBF)
    {
    p.PathAlgo=&PathFinders::NBF;
    }
    else if(i==DP)
    {
     p.PathAlgo=&PathFinders::Dynamic;

    }
    else{
    p.PathAlgo=nullptr;
    }
}
