////
//// Created by jakeb on 9/22/2019.
////
//
//#include "searching_Algos.h"
#include <queue>
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
        //Are these nodes the same that are in
        std::vector<Node<int>*>connections=g->getCons(current_index);
        for(int i=0;i<connections.size();i++) {
            Node<int> *temp = connections[i];
            //if not visited and not empty node
            if (!(g->getVisited()[temp->getData() - 1] == true)) {
                stack.push(temp);
                //Update parent child
                //Add current to tree
                TreeNode* new_Node=new TreeNode();
                new_Node->data = stack.top()->getData();
                new_Node->weight = stack.top()->getWeight();
                //Gets the treenode corresponding to current
                new_Node->parent = node_Tree.getLeaves(current_index + 1);
                node_Tree.insertNode(new_Node);
                if(stack.top()->getData()==dest)
                {
                    std::cout<<"here"<<std::endl;
                    std::vector<TreeNode*>saved=node_Tree.SavePath(stack.top()->getData());
                    for(int a=saved.size()-1;a>=0;a--)
                    {
                        std::cout<<saved[a]->data<<" ";
                    }
                    std::cout<<std::endl<<"here";
                    return;
                }
            }
        }
        //if top of the stack isn't visited and the stack isn't empty
        if(!(g->getVisited()[stack.top()->getData()-1]))
        {
            //Set current to top index
            current_index=stack.top()->getData()-1;
            current=g->Find(current_index,0);
        }

    }
//Debugging print parent child
node_Tree.SavePath(current_index+1);
}
void searching_Algos::DFS_Recursive(int src,int dest,Graph* g) {
    std::vector<int>path;
    DFS_reccur(src,dest,g,path);
}
void searching_Algos::DFS_reccur(int src, int dest,Graph* g,std::vector<int>&path) {
    g->getVisited()[src-1]=true;
    path.push_back(src);
    if(src==dest)
    {
        for(int i=0;i<path.size();i++)
        {
            std::cout<<path[i]<<" ";
        }
    }
    else{
        std::vector<Node<int>*>cons=g->getCons(src-1);
        for(int i=0;i<cons.size();i++)
        {
            if (!g->getVisited()[cons[i]->getData()-1]){
                DFS_reccur(cons[i]->getData(),dest,g,path);
            }


        }
    }


}
void searching_Algos::BFS_Iterative(int src, int dest, Graph *g) {
    //Stack of node pointers
    //std::stack<Node<int>*>stack;
    std::queue<Node<int>*>queue;
    Tree node_Tree(src);
    //Current row
    Node<int>*current;
    //Current row index
    int current_index=src-1;
    current=g->Find(current_index,0);
    //Push root node
    queue.push(current);
    //Loop until queue is empty
    while(!queue.empty())
    {
        //Set current as visited
        g->getVisited()[current_index]=true;
        //Pop from queue
        queue.pop();
        //Push all children onto stack
        //Are these nodes the same that are in
        std::vector<Node<int>*>connections=g->getCons(current_index);
        for(int i=0;i<connections.size();i++) {
            Node<int> *temp = connections[i];
            //if not visited and not empty node
            if (!(g->getVisited()[temp->getData() - 1] == true)) {
                queue.push(temp);
                //Update parent child
                //Add current to tree
                TreeNode* new_Node=new TreeNode();
                new_Node->data = temp->getData();
                new_Node->weight = temp->getWeight();
                //Gets the treenode corresponding to current
                new_Node->parent = node_Tree.getLeaves(current_index+1);
                node_Tree.insertNode(new_Node);
                if(queue.front()->getData()==dest)
                {
                    std::vector<TreeNode*>saved=node_Tree.SavePath(queue.front()->getData());
                    for(int a=saved.size()-1;a>=0;a--)
                    {
                        std::cout<<saved[a]->data<<" ";
                    }
                    return;
                }
            }
        }
        //if top of the stack isn't visited and the stack isn't empty
        if(!(g->getVisited()[queue.front()->getData()-1]))
        {
            //Set current to top index
            current_index=queue.front()->getData()-1;
            current=g->Find(current_index,0);
        }

    }
//Debugging print parent child
    node_Tree.SavePath(current_index+1);
}
void searching_Algos::BFS_Recursive(int src, int dest, Graph *g) {
    std::queue<int>queue;
    std::vector<int>path;
    queue.push(src);
    BFS_reccur(src,dest,g,queue,path);
}
void searching_Algos::BFS_reccur(int src, int dest, Graph* g,std::queue<int>&queue,std::vector<int>&path) {
    g->getVisited()[src-1]=true;
    path.push_back(src);
    if(src==dest)
    {
        for(int i=0;i<path.size();i++)
        {
            std::cout<<path[i]<<" ";
        }
    }
    else{
        //std::vector<Node<int>*>cons=g->getCons(src-1);
        std::vector<Node<int>*>cons=g->getCons((queue.front())-1);
        queue.pop();
        for(int i=0;i<cons.size();i++)
        {
            if (!g->getVisited()[cons[i]->getData()-1]){
                queue.push(cons[i]->getData());
                BFS_reccur(cons[i]->getData(),dest,g,queue,path);
            }


        }
    }
}
void searching_Algos::Djkstra(int src, int dest, Graph*g,std::map<std::pair<int,int>,int>&weight_values) {
    std::priority_queue<TreeNode*, std::vector<TreeNode*>, compare > priorityQueue;
    Tree tree(src);
    priorityQueue.push(tree.getRoot());
    int current_cost=0;
    int current_index=src-1;
    while(!priorityQueue.empty())
    {
        //Get connections of current index
        std::vector<Node<int>*>connections=g->getCons(current_index);
        //Pop current index from queue
        priorityQueue.pop();
        g->getVisited()[current_index]=true;
        for(int i=0;i<connections.size();i++)
        {
            Node<int>*temp=connections[i];
            if(!(g->getVisited()[temp->getData() - 1] == true))
            {
                //Add all the connections to tree and set current_index to lowest weight
                int weight=weight_values[std::make_pair(current_index+1,temp->getData())];
                //Add every node to tree
                TreeNode*new_Node=new TreeNode();
                new_Node->data = temp->getData();
                //Gets the treenode corresponding to current
                new_Node->parent = tree.getLeaves(current_index+1);
                //Set weight of new tree node
                Tree::setWeight(*new_Node,weight);
                tree.insertNode(new_Node);
                if(new_Node->data==dest)
                {
                    std::vector<TreeNode*>path= tree.SavePath(new_Node->data);
                    for(int i=0;i<path.size();i++)
                    {
                        std::cout<<path[i]->data<<" ";
                    }
                    return;
                }
                //Push all connections to priority queue lowest weight is top
                priorityQueue.push(new_Node);
            }

        }

       // current_cost+=new_Node->weight;
        //Make tree nodes at weights to compare paths
        //current_index=priorityQueue.top()->getData()-1;
        //Make priority queue of treenodes
        current_index=(priorityQueue.top()->data)-1;
        //Tree Node current can keep track of current weight of path

    }
}