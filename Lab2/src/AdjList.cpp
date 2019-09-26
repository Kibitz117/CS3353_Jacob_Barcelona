//
// Created by jakeb on 9/24/2019.
//

#include "AdjList.h"
void AdjList::add_Edge(int new_Node) {
    AdjNode *new_List;
    new_List->data=new_Node;
    list_Graph.push_back(new_List);
}
void AdjList::addNode(int dest,int src) {
    list_Graph[src]->potential_paths->addToTail(dest);
}
std::vector<AdjNode*>AdjList::getList()
{
    return  this->list_Graph;
}