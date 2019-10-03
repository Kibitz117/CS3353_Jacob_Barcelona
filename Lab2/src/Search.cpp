//
// Created by jakeb on 9/22/2019.
//
#include "Search.h"
//Loads in nodes,weights,and positions
void Search::Load(std::string fileName,std::string weights,std::string positions) {
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
    dataFile.close();
    dataFile.open(weights);
    std::string edge;
    while(getline(dataFile,line))
    {
        std::stringstream tokenize(line);
       std::string s;
       std::vector<std::string>tokens;
        while(getline(tokenize,s,','))
        {
            tokens.push_back(s);
        }
        int src=atoi(tokens[0].c_str());
        int dest=atoi(tokens[1].c_str());
        int weight=atoi(tokens[2].c_str());
        tokens.clear();
        list->Find(src-1,dest-1)->setWeight(weight);
        list->Find(dest-1,src-1)->setWeight(weight);
    }
list_Graph.toString();
searching_Algos s;
    Graph* g=&list_Graph;
    s.DFS_Iterative(2,12,g);


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
