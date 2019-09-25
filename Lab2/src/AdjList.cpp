//
// Created by jakeb on 9/24/2019.
//

#include "AdjList.h"
void AdjList::add_Edge(LinkedList<int> *new_List) {
    adjacency_graph.push_back(new_List);
}
void AdjList::add_Node(int new_Node,int list_Row) {
    adjacency_graph[list_Row].addToTail(new_Node);
}