////
//// Created by jakeb on 9/22/2019.
////
//
//#include "searching_Algos.h"
#include <queue>
#include "searching_Algos.h"
#include "Tree.h"
std::vector<int> searching_Algos::recur_path;
std::vector<int> searching_Algos::DFS_Iterative(int src, int dest, Graph *g,std::map<std::pair<int,int>,double>&weight_values,std::map<int,std::vector<int>>&node_positions) {
    //Stack of node pointers
    int vis=0;
    bool visited[g->getSize()];
    for(int i=0;i<g->getSize();i++)
    {
        visited[i]=false;
    }
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
       visited[current_index]=true;
       vis++;
        //Pop from stack
        stack.pop();
        //Push all children onto stack
        //Are these nodes the same that are in
        std::vector<Node<int>*>connections=g->getCons(current_index);
        for(int i=0;i<connections.size();i++) {
            Node<int> *temp = connections[i];
            double weight=weight_values[std::make_pair(current_index+1,temp->getData())];
            //if not visited and not empty node
            if (!(visited[temp->getData() - 1] == true)) {
                stack.push(temp);
                //Update parent child
                //Add current to tree
//                TreeNode* new_Node=new TreeNode();
//                new_Node->data = stack.top()->getData();
//                new_Node->weight = stack.top()->getWeight();
//                //Gets the treenode corresponding to current
//                new_Node->parent = node_Tree.getLeaves(current_index + 1);
//                node_Tree.insertNode(new_Node);
                //Add every node to tree
                TreeNode*parent=node_Tree.getLeaves(current_index+1);
                std::vector<int>empty;
                node_Tree.insertNode(parent,temp->getData(),weight,empty);
                if(stack.top()->getData()==dest)
                {
                    std::vector<TreeNode*>saved=node_Tree.SavePath(stack.top()->getData());
                    std::vector<int>path;
                    for(int a=saved.size()-1;a>=0;a--)
                    {
                        path.push_back(saved[a]->data);
                    }
                    std::cout<<std::endl;
                    path.push_back(vis);
                    return path;
                }
            }
        }

        //Set current to top index
            current_index=stack.top()->getData()-1;
            current=g->Find(current_index,0);

    }
    std::vector<int>empty;
return empty;
}
std::vector<int> searching_Algos::DFS_Recursive(int src,int dest,Graph* g,std::map<std::pair<int,int>,double>&weight_values,std::map<int,std::vector<int>>&node_positions) {
    std::vector<int>path;
    bool visited[g->getSize()];
    for(int i=0;i<g->getSize();i++)
    {
        visited[i]=false;
    }
    recur_path.clear();
    DFS_reccur(src,dest,g,path,visited);
    return recur_path;
}
void searching_Algos::DFS_reccur(int src, int dest,Graph* g,std::vector<int>&path,bool*visited) {
    visited[src]=true;
    path.push_back(src);
    if(src==dest)
    {
        for(int i=0;i<path.size();i++)
        {
            recur_path.push_back(path[i]);
        }
    }
    std::vector<Node<int>*>cons=g->getCons(src-1);
    for(int i=0;i<cons.size();i++)
    {
        if ((!visited[cons[i]->getData()])){
            DFS_reccur(cons[i]->getData(),dest,g,path,visited);
        }


    }


    return;




}
std::vector<int> searching_Algos::BFS_Iterative(int src, int dest, Graph *g,std::map<std::pair<int,int>,double>&weight_values,std::map<int,std::vector<int>>&node_positions) {
    int vis=0;
    bool visited[g->getSize()];
    for(int i=0;i<g->getSize();i++)
    {
        visited[i]=false;
    }
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
        visited[current_index]=true;
        vis++;
        //Pop from queue
        queue.pop();
        //Push all children onto stack
        //Are these nodes the same that are in
        std::vector<Node<int>*>connections=g->getCons(current_index);
        for(int i=0;i<connections.size();i++) {
            Node<int> *temp = connections[i];
            //if not visited and not empty node
            if (!(visited[temp->getData() - 1] == true)) {
                queue.push(temp);
                //Update parent child
                //Add current to tree
//                TreeNode* new_Node=new TreeNode();
//                new_Node->data = temp->getData();
//                new_Node->weight = temp->getWeight();
//                //Gets the treenode corresponding to current
//                new_Node->parent = node_Tree.getLeaves(current_index+1);
//                node_Tree.insertNode(new_Node);
                double weight=weight_values[std::make_pair(current_index+1,temp->getData())];
                //Add every node to tree
                TreeNode*parent=node_Tree.getLeaves(current_index+1);
                std::vector<int>empty;
                node_Tree.insertNode(parent,temp->getData(),weight, empty);
                if(queue.front()->getData()==dest)
                {
                    std::vector<TreeNode*>saved=node_Tree.SavePath(queue.front()->getData());
                    std::vector<int>path;
                    for(int a=saved.size()-1;a>=0;a--)
                    {
                        path.push_back(saved[a]->data);
                    }
                    path.push_back(vis);
                    return path;
                }

            }
        }
        //if top of the stack isn't visited and the stack isn't empty
            //Set current to top index
            current_index=queue.front()->getData()-1;
            current=g->Find(current_index,0);

    }
    std::vector<int>empty;
    return empty;
}
std::vector<int> searching_Algos::BFS_Recursive(int src, int dest, Graph *g,std::map<std::pair<int,int>,double>&weight_values,std::map<int,std::vector<int>>&node_positions) {
    std::queue<int>queue;
    std::vector<int>path;
    queue.push(src);
    bool visited[g->getSize()];
    for(int i=0;i<g->getSize();i++)
    {
        visited[i]=false;
    }
    recur_path.clear();
    BFS_reccur(src,dest,g,queue,path,visited);
    return recur_path;
}
void searching_Algos::BFS_reccur(int src, int dest, Graph* g,std::queue<int>&queue,std::vector<int>&path,bool*visited) {
    visited[src-1]=true;
    path.push_back(src);
    if(queue.empty())
    {
        return;
    }
    if(src==dest)
    {
        for(int i=0;i<path.size();i++)
        {
            recur_path.push_back(path[i]);
        }
    }
    else{
        //std::vector<Node<int>*>cons=g->getCons(src-1);
        std::vector<Node<int>*>cons=g->getCons((queue.front())-1);
        queue.pop();
        for(int i=0;i<cons.size();i++)
        {
            if (!visited[cons[i]->getData()-1]){
                queue.push(cons[i]->getData());
                BFS_reccur(cons[i]->getData(),dest,g,queue,path,visited);
            }


        }
        return;
    }
}

std::vector<int> searching_Algos::Djkstra(int src, int dest, Graph*g,std::map<std::pair<int,int>,double>&weight_values,std::map<int,std::vector<int>>&node_positions) {
    int vis=0;
    bool visited[g->getSize()];
    for(int i=0;i<g->getSize();i++)
    {
        visited[i]=false;
    }
    std::priority_queue<TreeNode*, std::vector<TreeNode*>, compare > priorityQueue;
    Tree tree(src);
    priorityQueue.push(tree.getRoot());
    int current_cost=0;
    int current_index=src-1;
    while(!priorityQueue.empty())
    {
        if(priorityQueue.top()->data==dest)
        {
            break;
        }
        //Get connections of current index
        std::vector<Node<int>*>connections=g->getCons(current_index);
        //Pop current index from queue
        priorityQueue.pop();
        visited[current_index]=true;
        vis++;
        for(int i=0;i<connections.size();i++)
        {
            Node<int>*temp=connections[i];
            if(!(visited[temp->getData() - 1] == true))
            {
                //Add all the connections to tree and set current_index to lowest weight
                double weight=weight_values[std::make_pair(current_index+1,temp->getData())];
                //Add every node to tree
                TreeNode*parent=tree.getLeaves(current_index+1);
                std::vector<int>empty;
                tree.insertNode(parent,temp->getData(),weight, empty);
//                TreeNode*new_Node=new TreeNode();
//                new_Node->data = temp->getData();
//                //Gets the treenode corresponding to current
//                new_Node->parent = tree.getLeaves(current_index+1);
//                //Set weight of new tree node
//                Tree::setWeight(*new_Node,weight);
//                Tree::setPosition(*new_Node,{0,0,1});
             //   tree.insertNode(new_Node);
                //Push all connections to priority queue lowest weight is top
                priorityQueue.push(tree.getLeaves(temp->getData()));
            }

        }

       // current_cost+=new_Node->weight;
        //Make tree nodes at weights to compare paths
        //current_index=priorityQueue.top()->getData()-1;
        //Make priority queue of treenodes
        current_index=(priorityQueue.top()->data)-1;
        //Tree Node current can keep track of current weight of path

    }
    std::vector<TreeNode*>saved= tree.SavePath(dest);
    std::vector<int>path;
    for(int i=saved.size()-1;i>=0;i--)
    {
        path.push_back(saved[i]->data);
    }
    weight_values[std::make_pair(src,dest)]=tree.getLeaves(dest)->weight;
    path.push_back(vis);
    return path;
}
std::vector<int> searching_Algos::A_Star(int src, int dest, Graph *g, std::map<std::pair<int, int>, double> &weight_values,
                                         std::map<int, std::vector<int>> &node_positions) {
    int vis=0;
    bool visited[g->getSize()];
    for(int i=0;i<g->getSize();i++)
    {
        visited[i]=false;
    }
    std::priority_queue<TreeNode*, std::vector<TreeNode*>, compare > priorityQueue;
    Tree tree(src);
    tree.getRoot()->position=node_positions[src];
    priorityQueue.push(tree.getRoot());
    int current_index=src-1;
    while(!priorityQueue.empty())
    {
        if(priorityQueue.top()->data==dest)
        {
            break;
        }
        //Get connections of current index
        std::vector<Node<int>*>connections=g->getCons(current_index);
        //Pop current index from queue
        priorityQueue.pop();
        visited[current_index]=true;
        vis++;
        for(int i=0;i<connections.size();i++)
        {
            Node<int>*temp=connections[i];
            if(!(visited[temp->getData() - 1] == true))
            {
                //Add all the connections to tree and set current_index to lowest weight
                double weight=weight_values[std::make_pair(current_index+1,temp->getData())];
                std::vector<int>position=node_positions[temp->getData()];
                //Add every node to tree
//                TreeNode*new_Node=new TreeNode();
//                new_Node->data = temp->getData();
//                //Gets the treenode corresponding to current
//                new_Node->parent = tree.getLeaves(current_index+1);
//                //Set weight of new tree node
//                Tree::setWeight(*new_Node,weight);
//                Tree::setPosition(*new_Node,position);
//                tree.insertNode(new_Node);
                //Add every node to tree
                TreeNode*parent=tree.getLeaves(current_index+1);
                tree.insertNode(parent,temp->getData(),weight, position);
                //Push all connections to priority queue lowest weight is top
                priorityQueue.push(tree.getLeaves(temp->getData()));
            }

        }

        //Make tree nodes at weights to compare paths
        //current_index=priorityQueue.top()->getData()-1;
        //Make priority queue of treenodes
        current_index=(priorityQueue.top()->data)-1;
        //Tree Node current can keep track of current weight of path

    }
    std::vector<TreeNode*>saved= tree.SavePath(dest);
                    std::vector<int>path;
                    for(int i=saved.size()-1;i>=0;i--)
                    {
                        path.push_back(saved[i]->data);
                    }
                    //A way to retrieve the final cost in stats
    weight_values[std::make_pair(src,dest)]=tree.getLeaves(dest)->weight;
                    //A way to retrieve the final distance in stats
    weight_values[std::make_pair(dest,src)]=tree.getLeaves(dest)->distance_parent;
                    path.push_back(vis);
                    return path;

}