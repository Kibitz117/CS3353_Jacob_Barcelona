//
// Created by jakeb on 9/22/2019.
//

#include "Tree.h"
Tree::Tree() {
root=nullptr;
depth=0;
total=0;
}
Tree::Tree(int r) {
    TreeNode *root_Node;
    root_Node->data = r;
    root = root_Node;
    depth = 0;
    total = 1;
    relationships.insert(root_Node,root_Node);
}

TreeNode* Tree::find(int data) {
    if(root->data==data)
    {
        return root;
    }
    else
    {
        TreeNode* current=root;
        while(!current->data==data)
        {

        }
    }
}
void Tree::insertNode(int par,int src) {
        TreeNode* new_Node;
        new_Node->data=src;
        //Do I need a find function
        new_Node->parent=par;
        new_Node->parent->children.push_back(new_Node);
        relationships.insert(new_Node->parent,new_Node);
        total++;


}
//Returns vector of children
std::vector<TreeNode*> Tree::getChildren(TreeNode*par) {
    return par->children;
}
void Tree::deleteTree() {
    delete root;
}