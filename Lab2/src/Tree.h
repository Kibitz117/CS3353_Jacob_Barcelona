//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_GRAPH_H
#define SEARCHING_GRAPH_H

#include "LinkedList.h"
#include <map>
#include <vector>
struct TreeNode{
    int data;
    TreeNode* parent;
    std::vector<TreeNode*>children;
    bool visited=false;

};
class Tree {
public:
    Tree();
    Tree(int);
    std::vector<TreeNode*> getChildren(TreeNode*);
    void insertNode(TreeNode*);
    void deleteTree();
    TreeNode* find(int);

private:
    TreeNode* root;
    int depth;
    int total;
    std::map<TreeNode*,TreeNode*>relationships;
};


#endif //SEARCHING_GRAPH_H
