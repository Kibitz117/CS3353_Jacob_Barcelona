//
// Created by jakeb on 9/22/2019.
//

#include <sstream>
#include "Search.h"
void Search::Load(std::string fileName) {
    std::fstream dataFile;
    dataFile.open(fileName);
    AdjList list_Graph;
    std::string line;
    while(getline(dataFile,line))
    {
        int count=0;
        int count2=0;
        std::stringstream linestream(line);
        std::string node;
        while(getline(linestream,node,','))
        {
            if(count2==0)
            {
                int temp=atoi(node.c_str());
                list_Graph.add_Edge(temp);
            }
            else{
                int temp=atoi(node.c_str());
                list_Graph.add_Node(temp,count);
            }
            count2++;

        }
        count++;

    }
    //Read line tokenize commas
    //First number is adjacency nodes
    //Following are the adjacency nodes children in Linked List
    //Find way to abstract with AdjMatrix
}