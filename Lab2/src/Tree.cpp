//
// Created by jakeb on 9/22/2019.
//

#include "Tree.h"
Tree::Tree() {
root=nullptr;
depth=0;
total=0;
}
void Tree::insertNode(TreeNode* par,int src) {
    if(par==nullptr)
    {
        root->data=src;
        root->parent=nullptr;
    }
    else
    {
        TreeNode* new_Node;
        new_Node->data=src;
        new_Node->parent=par;
        new_Node->parent->children.push_back(new_Node);

    }
}
std::vector<TreeNode*> Tree::getChildren(TreeNode*par) {
    return par->children;
}