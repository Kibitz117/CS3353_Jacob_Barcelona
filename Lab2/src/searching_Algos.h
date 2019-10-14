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
#include <queue>
struct compare{
    bool operator()(const TreeNode*l,const TreeNode*r)
    {
       if(l->weight>r->weight)
           return true;
       return false;
    }
};
class searching_Algos {
public:
   void DFS_Iterative(int,int,Graph* g);
   void DFS_Recursive(int,int,Graph* g);
   void BFS_Iterative(int,int,Graph* g);
   void BFS_Recursive(int,int,Graph* g);
   void Djkstra(int,int,Graph*g,std::map<std::pair<int,int>,int>&);

private:
    void DFS_reccur(int,int,Graph *g,std::vector<int>&);
    void BFS_reccur(int,int, Graph*g,std::queue<int>&,std::vector<int>&);
};


#endif //SEARCHING_SEARCHING_ALGOS_H
