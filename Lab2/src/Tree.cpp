//////
////// Created by jakeb on 9/22/2019.
//////
////
#include "Tree.h"
Tree::Tree() {
root=nullptr;
depth=0;
total=0;
}
Tree::Tree(int r) {
    TreeNode *root_Node=new TreeNode();
    root_Node->data = r;
    root_Node->parent=nullptr;
    root = root_Node;
    depth = 0;
    total = 1;
    root_Node->weight=0;
    this->leaves.insert(std::make_pair(root->data,root));
}
Tree::~Tree() {
    delete root;
}
void Tree::insertNode(TreeNode*parent,int data,double weight,std::vector<int>&position) {
    //Update leaf pointers
    TreeNode*new_Node=new TreeNode();
    new_Node->data=data;
    new_Node->parent=parent;
    Tree::setWeight(*new_Node,weight);
    if(!position.empty())
    {
        new_Node->position=position;
        Tree::setPosition(*new_Node);
    }
    total++;
    leaves[data]=new_Node;
//    std::map<int,TreeNode*>::iterator it = leaves.find(new_Node->data);
//    if(it==leaves.end())
//    {
//        leaves[new_Node->data]=new_Node;
//        //Remove parent from leaf node pointers
//        //This line isn't working properly
//        //Push back new Node to its parent's vector of children
//        new_Node->parent->children.push_back(new_Node);
//        total++;
//
//    }


}
//Returns vector of children
std::vector<TreeNode*> Tree::getChildren(TreeNode*par) {
    return par->children;
}
void Tree::deleteTree() {

}
TreeNode* Tree::getLeaves(int i) {
        return leaves[i];
}
TreeNode* Tree::getParent(TreeNode *curr) {
    return curr->parent;
}
TreeNode* Tree::getRoot() {
    return root;
}
std::vector<TreeNode*> Tree::SavePath(int dest) {
    std::vector<TreeNode*>path;
    TreeNode*curr=leaves[dest];
    while(curr!= nullptr)
    {
        path.push_back(curr);
        curr=curr->parent;
    }
    return path;

}
void Tree::setWeight(TreeNode &node,double weight) {

    weight+=node.parent->weight;
    node.weight=weight;
}
//Map of leaf nodes
int Tree::getShortest(int current_weight) {
    TreeNode*small;
    for(std::map<int,TreeNode*>::iterator it=leaves.begin(); it!=leaves.end(); ++it)
    {
        if(it->second->weight<current_weight&&it->second->children.empty())
        {
            small=it->second;
        }
    }
    return small->data;
}
void Tree::setPosition(TreeNode &node) {
    int dx=node.position[0]-node.parent->position[0];
    int dy=node.position[1]-node.parent->position[1];
    int dz=node.position[2]-node.parent->position[2];
    double distance=sqrt((dx^2)+(dy^2)+(dz^2));
    node.distance_parent=distance;
}
