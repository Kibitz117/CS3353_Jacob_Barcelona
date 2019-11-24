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
    std::vector<int>path={2,3,4,5,6,7,8,9,10,11};
//    TabuSearch t(src,10000,path,node_map);
//    t.Execute(10000);

    GeneticAlgorithm a(src,1000,path,node_map);
        a.evolve(1000);

    auto end_time = std::chrono::high_resolution_clock::now();
    time=std::chrono::duration_cast<std::chrono::nanoseconds>(end_time-start_time).count();

}
void Search::Stats(int algo) {
    if(algo==GA)
    {
        std::cout<<"Genetic Algorithm"<<std::endl;
        std::cout<<time<<" ns"<<std::endl;
    }
    else if(algo==TABU)
    {
        std::cout<<"Tabu Search"<<std::endl;
        std::cout<<time<<" ns"<<std::endl;
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
void Search::Configure() {

}
void Search::Select(int i) {

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
