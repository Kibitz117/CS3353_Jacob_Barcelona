//
// Created by jakeb on 9/22/2019.
//

#include "searching_Algos.h"
Tree& searching_Algos::DFS_Iterative(int src, int dest,AdjList adj_Graph) {
    std::stack<Node*>searching;
    Tree path;
    searching.push(adj_Graph.getList()[src]->adj_Node);
    for(int i=0;i<adj_Graph.getList()[src]->potential_paths->getSize();i++)
    {
        searching.push(adj_Graph.getList()[src]->potential_paths[i].);
    }


    return path;
}