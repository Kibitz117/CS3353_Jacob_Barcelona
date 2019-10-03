////
//// Created by jakeb on 9/22/2019.
////
//
//#include "searching_Algos.h"
#include "searching_Algos.h"
#include "Tree.h"

void searching_Algos::DFS_Iterative(int src, int dest, Graph *g) {
    //Stack of node pointers
    std::stack<Node<int>*>stack;
    Tree node_Tree(src);
    //Current row
    Node<int>*current;
    //Current row index
    int current_index=src-1;
    current=g->Find(current_index,0);
    //Push root node
    stack.push(current);
    //Loop until stack is empty
    while(!stack.empty())
    {
        //Set current as visited
        g->getVisited()[current_index]=true;
        //Pop from stack
        stack.pop();
        //Push all children onto stack
        for(int i=0;i<g->getSize();i++)
        {//Are these nodes the same that are in
            Node<int>*temp=g->Find(current_index,i);
            //if not visited and not empty node
            if(!(g->getVisited()[temp->getData()-1]==true)&&!(g->Find(current_index,i)->getData()==0))
            {
                stack.push(temp);
                //Update parent child
                //Add current to tree
                TreeNode new_Node;
                new_Node.data=stack.top()->getData();
                new_Node.weight=stack.top()->getWeight();
                //Gets the treenode corresponding to current
                new_Node.parent=node_Tree.getLeaves(current_index+1);
                node_Tree.insertNode(&new_Node);
            }
        }
        //if top of the stack isn't visited and the stack isn't empty
        if(!(g->getVisited()[stack.top()->getData()-1]))
        {
            //Set current to top index
            current_index=stack.top()->getData()-1;
            current=g->Find(current_index,0);
        }
        if(current->getData()==dest)
        {
            break;
        }

    }
//Debugging print parent child
node_Tree.SavePath(current_index+1);
}
void searching_Algos::DFS_Recursive(int src,int dest,Graph* g) {

    DFS_reccur(src,dest,g);
}
void searching_Algos::DFS_reccur(int src, int dest,Graph* g) {
    g->getVisited()[src-1]=true;
    std::cout<<src;
    if(src==dest)
    {
        //save();
        return;
    }
    std::vector<Node<int>*>cons=g->getCons(src);
    for(int i=0;i<cons.size();i++)
    {
        if (!g->getVisited()[i])
            DFS_reccur(i,dest,g);
    }

}