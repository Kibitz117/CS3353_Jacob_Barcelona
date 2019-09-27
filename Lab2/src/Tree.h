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
    struct TreeNode* parent;
    std::vector<struct TreeNode*>children;
    bool visited=false;

};
class Tree {
public:
    Tree();
    Tree(int);
    std::vector<struct TreeNode*> getChildren(struct TreeNode*);
    void insertNode(struct TreeNode*);
    void deleteTree();
    struct TreeNode* find(int);

private:
    struct TreeNode* root;
    int depth;
    int total;
    std::map<struct TreeNode*,struct TreeNode*>relationships;
};


#endif //SEARCHING_GRAPH_H
