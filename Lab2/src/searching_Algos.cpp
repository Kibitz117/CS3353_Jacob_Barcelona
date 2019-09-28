////
//// Created by jakeb on 9/22/2019.
////
//
//#include "searching_Algos.h"
//Tree& searching_Algos::DFS_Iterative(int src, int dest,AdjList adj_Graph) {
//    std::stack<TreeNode*>searching;
//    int curr_index=std::find(adj_Graph.getList().begin(),adj_Graph.getList().end(),src)-adj_Graph.getList().begin();
//    struct TreeNode*current;
//    current->data=adj_Graph.getList()[curr_index]->adj_Node->data;
//    Tree path(current->data);
//    searching.push(current);
//while(!searching.empty())
//{
//    for(int i=0;i<adj_Graph.getList()[curr_index]->potential_paths->getSize();i++)
//    {
//        if(adj_Graph.getList()[curr_index]->potential_paths->operator[](i)->visited==false)
//        {
//            TreeNode* temp;
//            temp->data=adj_Graph.getList()[src]->potential_paths->operator[](i)->data;
//            temp->parent=current;
//            searching.push(temp);
//        }
//    }
//    current->visited=true;
//    searching.pop();
//    path.insertNode(searching.top());
//    current=searching.top();
//    if(current->data==src)
//        break;
//    curr_index=std::find(adj_Graph.getList().begin(),adj_Graph.getList().end(),current->data)-adj_Graph.getList().begin();
//
//}
//
//
//    return path;
//}