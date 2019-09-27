//
// Created by jakeb on 9/24/2019.
//

#include "AdjList.h"
AdjList::AdjList(int size) {
    this->list_Graph.reserve(size);
}
void AdjList::add_Edge(int new_Node) {
    AdjNode *new_List;
    new_List->data=new_Node;
    list_Graph.push_back(new_List);
}
void AdjList::addNode(int src,int dest) {
    AdjNode* new_Node;
    new_Node->data=src;
    auto it=std::find (list_Graph.begin(),list_Graph.end(),src);
    if(it==list_Graph.end())
    {
        add_Edge(src);
    }
    list_Graph[src]->potential_paths->addToTail(dest);
}
std::vector<AdjNode*>AdjList::getList()
{
    return  this->list_Graph;
}