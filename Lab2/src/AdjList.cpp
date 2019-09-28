//
// Created by jakeb on 9/24/2019.
//

#include "AdjList.h"
AdjList::AdjList(int size) {
    this->list_Graph.reserve(size);
    this->numVerticies=size;
    for(int i=0;i<size;i++)
    {
        add_Edge(i+1);
    }
}
void AdjList::add_Edge(int new_Node) {
    AdjNode new_List;
    new_List.adj_Node->data=new_Node;
    list_Graph.push_back(&new_List);
}
void AdjList::addNode(int src,int dest) {
    list_Graph[src-1]->potential_paths->addToTail(dest);
}
std::vector<AdjNode*>AdjList::getList()
{
    return  this->list_Graph;
}