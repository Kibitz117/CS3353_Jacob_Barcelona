//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_GRAPH_H
#define SEARCHING_GRAPH_H


#include "Node.h"
#include <vector>
struct TreeNode{
    int data;
    TreeNode* parent;
    std::vector<TreeNode*>children;

};
class Tree {
public:
    Tree();
    std::vector<TreeNode*> getChildren(TreeNode*);
    void insertNode(TreeNode*,int);

private:
    TreeNode* root;
    int depth;
    int total;
};


#endif //SEARCHING_GRAPH_H
