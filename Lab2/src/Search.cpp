//
// Created by jakeb on 9/22/2019.
//
#include <sstream>
#include "Search.h"
void Search::Load(std::string fileName) {
    std::fstream dataFile;
    dataFile.open(fileName);
    std::string line;
    int count=0;
std::vector<std::stringstream> streams;
    while(getline(dataFile,line))
    {
        std::stringstream linestream(line);
        streams.push_back(linestream);
        count++;

    }
    AdjList list_Graph(count);
    int count2=1;
    for(int i=0;i<streams.size();i++)
    {
        std::string node;
        while(getline(streams[i],node,','))
        {
            int temp=atoi(node.c_str());
            list_Graph.addNode(temp,count2);
        }
    }

    //Read line tokenize commas
    //First number is adjacency nodes
    //Following are the adjacency nodes children in Linked List
    //Find way to abstract with AdjMatrix
}