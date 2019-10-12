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
#include "Node.h"
#include <map>
class searching_Algos {
public:
   void DFS_Iterative(int,int,Graph* g);
   void DFS_Recursive(int,int,Graph* g);
   void BFS_Iterative(int,int,Graph* g);
   void BFS_Recursive(int,int,Graph* g);

private:
    void DFS_reccur(int,int,Graph *g,std::vector<int>&);
    void BFS_reccur(int,int Graph*g,std::queue<int>&);
};


#endif //SEARCHING_SEARCHING_ALGOS_H
