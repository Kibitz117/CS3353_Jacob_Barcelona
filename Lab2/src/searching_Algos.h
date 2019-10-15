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
#include <vector>
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
  static std::vector<int> DFS_Iterative(int,int,Graph* g,std::map<std::pair<int,int>,int>&);
   static std::vector<int> DFS_Recursive(int,int,Graph* g,std::map<std::pair<int,int>,int>&);
   static std::vector<int> BFS_Iterative(int,int,Graph* g,std::map<std::pair<int,int>,int>&);
   static std::vector<int> BFS_Recursive(int,int,Graph* g,std::map<std::pair<int,int>,int>&);
  static std::vector<int> Djkstra(int,int,Graph*g,std::map<std::pair<int,int>,int>&);

private:
    static void DFS_reccur(int,int,Graph *g,std::vector<int>&,bool*);
    static void BFS_reccur(int,int, Graph*g,std::queue<int>&,std::vector<int>&,bool*);
    static std::vector<int>recur_path;
};


#endif //SEARCHING_SEARCHING_ALGOS_H
