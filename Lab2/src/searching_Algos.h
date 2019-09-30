//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCHING_ALGOS_H
#define SEARCHING_SEARCHING_ALGOS_H

#include "Graph.h"
//#include "Tree.h"
#include "AdjList.h"
#include "Search.h"
#include <stack>
#include "LinkedList.h"
#include "Node.h"
class searching_Algos {
public:
   std::vector<std::vector<Node<int>>>& DFS_Iterative(int,int,AdjList<Node<int>>);
   std::string DFS_Recursive();
   std::string BFS_Iterative();

private:
    void* graph_pointer;
};


#endif //SEARCHING_SEARCHING_ALGOS_H
