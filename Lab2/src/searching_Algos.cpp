//
// Created by jakeb on 9/22/2019.
//

#include "searching_Algos.h"
Tree& searching_Algos::DFS_Iterative(int src, int dest,AdjList<Node> adj_Graph) {
    std::stack<TreeNode*>searching;
    int curr_index=adj_Graph.Find(src);
    struct TreeNode*current;
    current->data=src;
    Tree path(current->data);
    searching.push(current);
while(!searching.empty())
{
    for(int i=0;i<adj_Graph.getSize();i++)
    {
        if(adj_Graph.getList()[curr_index].getEdges().operator[](i).isVisited()==false)
        {
            TreeNode* temp;
            temp->data=adj_Graph.getList()[src].getEdges()->operator[](i)->data;
            temp->parent=current;
            searching.push(temp);
        }
    }
    current->visited=true;
    searching.pop();
    path.insertNode(searching.top());
    current=searching.top();
    if(current->data==src)
        break;
    curr_index=std::find(adj_Graph.getList().begin(),adj_Graph.getList().end(),current->data)-adj_Graph.getList().begin();

}


    return path;
}