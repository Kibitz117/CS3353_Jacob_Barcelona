//
// Created by jakeb on 9/22/2019.
//

#include "searching_Algos.h"
Tree& searching_Algos::DFS_Iterative(int src, int dest,AdjList adj_Graph) {
    std::stack<Node*>searching;
    int curr_index=std::find(adj_Graph.getList().begin(),adj_Graph.getList().end(),src)-adj_Graph.getList().begin();
    struct Node*current=adj_Graph.getList()[curr_index]->adj_Node;
    Tree path(current->data);
    searching.push(current);
while(!searching.empty())
{
    for(int i=0;i<adj_Graph.getList()[curr_index]->potential_paths->getSize();i++)
    {
        if(adj_Graph.getList()[curr_index]->potential_paths->operator[](i)->visited==false)
        {
            searching.push(adj_Graph.getList()[src]->potential_paths->operator[](i));
        }
    }
    current->visited=true;
    searching.pop();
    path.insertNode(current->data,searching.top()->data);
    current=searching.top();
    if(current->data==src)
        break;
    curr_index=std::find(adj_Graph.getList().begin(),adj_Graph.getList().end(),current->data)-adj_Graph.getList().begin();

}


    return path;
}