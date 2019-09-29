//
// Created by jakeb on 9/22/2019.
//
#include <sstream>
#include "Search.h"
#include "AdjMatrix.h"

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
    AdjMatrix list_Graph(count);
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
                list_Graph.addNode(i+1,temp);
            }
            count2++;

        }
    }
    list=&list_Graph;
    list_Graph.toString();

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
