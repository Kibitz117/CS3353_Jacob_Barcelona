//
// Created by jakeb on 9/24/2019.
//

#include "AdjList.h"
void AdjList::add_Edge(AdjNode *new_List) {
    list_Graph.push_back(new_List);
}
void AdjList::add_Node(int dest,int src) {
    list_Graph[src]->potential_paths->addToTail(dest);
}
std::vector<AdjNode*>AdjList::getList()
{
    return  this->list_Graph;
}