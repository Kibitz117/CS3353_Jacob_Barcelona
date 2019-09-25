//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_SEARCHING_ALGOS_H
#define SEARCHING_SEARCHING_ALGOS_H

#include "Tree.h"
#include <list>
#include "Search.h"
class searching_Algos {
public:
   std::string DFS_Iterative(int,int);
   std::string DFS_Recursive();
   std::string BFS_Iterative();

private:
    void* graph_pointer;
};


#endif //SEARCHING_SEARCHING_ALGOS_H
