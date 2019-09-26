//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_GRAPH_H
#define SEARCHING_GRAPH_H


#include <vector>
struct TreeNode{
    int data;
    TreeNode* parent;
    std::vector<TreeNode*>children;

};
class Tree {
public:
    Tree();
    Tree(int);
    std::vector<TreeNode*> getChildren(TreeNode*);
    void insertNode(int,int);
    void deleteTree();
    TreeNode* find(int);

private:
    TreeNode* root;
    int depth;
    int total;
};


#endif //SEARCHING_GRAPH_H
