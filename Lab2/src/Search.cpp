//
// Created by jakeb on 9/22/2019.
//
#include "Search.h"

void Search::Load(std::string fileName) {
    std::fstream dataFile;
    dataFile.open(fileName);
    std::string line;
    int count=0;
std::vector<std::string> streams;
    while(getline(dataFile,line))
    {
        streams.push_back(line);
        count++;

    }
    AdjList<int> list_Graph(count);
    list=&list_Graph;
    for(int i=0;i<streams.size();i++)
    {
        std::string node;
        int count2=0;
        std::stringstream stream(streams[i]);
        while(getline((stream),node,','))
        {
            if(count2==0)
            {

            }
            else{
                int temp=atoi(node.c_str());
                list->addNode(i+1,temp);
            }
            count2++;

        }
    }
    for(int i=0;i<list_Graph.getList().getSize();i++)
    {
        std::cout<<list_Graph.getList()[i].getNode().getData()<<": ";
        for(int z=0;z<list_Graph.getList()[i].getEdges().getSize();z++)
        {
            std::cout<<list_Graph.getList()[i].getEdges().operator[](z)<<" ";
        }
        std::cout<<std::endl;
    }

    //Read line tokenize commas
    //First number is adjacency nodes
    //Following are the adjacency nodes children in Linked List
    //Find way to abstract with AdjMatrix
}
void Search::Execute(){

}//Running switch statement
void Search::Display(){

}
void Search::Stats(int algo){

}
void Search::Select(int){

}//Select active algorithm
void Search::Save(std::string,int,std::string){

}
void Search::Configure(){

}
void Search::Clear()
{

}
