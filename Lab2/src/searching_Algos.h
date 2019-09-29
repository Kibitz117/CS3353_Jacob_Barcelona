//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCHING_ALGOS_H
#define SEARCHING_SEARCHING_ALGOS_H

#include "Graph.h"
#include "Tree.h"
#include "AdjList.h"
#include "Search.h"
#include <stack>
#include "LinkedList.h"
class searching_Algos {
public:
   Tree& DFS_Iterative(int,int,AdjList<int>);
   std::string DFS_Recursive();
   std::string BFS_Iterative();

private:
    void* graph_pointer;
};


#endif //SEARCHING_SEARCHING_ALGOS_H
