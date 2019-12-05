//
// Created by jakeb on 10/23/2019.
//
#include "Search.h"
void Search::Load(std::string path, int structure) {
    FileLoader loader;
s=loader.load(path,structure);
if(structure==0)
{
    node_map= dynamic_cast<MapHandler *>(s)->getMap();

}//p.setMap(map->getMap());
 }
 void Search::Execute(int src) {
    auto start_time = std::chrono::high_resolution_clock::now();
   //path=(p.*(p.PathAlgo))(src);
  tsp->Run(700);

    auto end_time = std::chrono::high_resolution_clock::now();
    time=std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();
    delete(tsp);

}
void Search::Stats(int algo) {
    if(algo==GA)
    {
        std::cout<<"Genetic Algorithm"<<std::endl;
        std::cout<<time<<" ns"<<std::endl;
        std::cout<<path.size()+1<<" nodes"<<std::endl;
        path.clear();
    }
    else if(algo==TABU)
    {
        std::cout<<"Tabu Search"<<std::endl;
        std::cout<<time<<" ns"<<std::endl;
        std::cout<<path.size()+1<<" nodes"<<std::endl;
        path.clear();
    }
//if(algo==NBF)
//{
//    std::cout<<"Brute Force"<<std::endl;
//    std::cout<<"The cost of the shortest path is "<<p.cost<<std::endl;
//    std::cout<<"The path is ";
//    std::cout<<1<<" ";
//    for(int i=0;i<path.size();i++)
//    {
//        std::cout<<path[i]<<" ";
//    }
//    std::cout<<1<<" "<<std::endl;
//    std::cout<<time<<" ns"<<std::endl;
//    std::cout<<"Nanoseconds per step "<<p.step;
//}
//else if(algo==DP)
//{
//    std::cout<<"Dynamic Programming"<<std::endl;
//    std::cout<<"The cost of the shortest path is "<<p.cost<<std::endl;
//    std::cout<<"The path is ";
//    for(int i=0;i<path.size();i++)
//    {
//        std::cout<<path[i]<<" ";
//    }
//    std::cout<<std::endl;
//    std::cout<<time<<" ns"<<std::endl;
//    std::cout<<"Nanoseconds per step "<<p.step;
//}
}
void Search::Save(std::string, int, std::string) {
FileLoader loader;
std::string out="path.txt";
loader.output(path,out);
}
void Search::Display() {
for(int i=0;i<path.size();i++)
{
    std::cout<<path[i]<<" ";
}
}
void Search::Select(int i) {
if(i==TABU)
{
    tsp=new TabuSearch(1,400,path,node_map);
}
else if(i==GA)
{
    tsp=new GeneticAlgorithm(1,20,path,node_map);
}
//    if(i==NBF)
//    {
//    p.PathAlgo=&PathFinders::NBF;
//    }
//    else if(i==DP)
//    {
//     p.PathAlgo=&PathFinders::Dynamic;
//
//    }
//    else{
//    p.PathAlgo=nullptr;
//    }
}
void Search::Configure(int size) {
    for(int i=2;i<=size;i++)
    {
        path.push_back(i);
    }
}