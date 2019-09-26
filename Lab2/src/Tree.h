//
// Created by jakeb on 9/22/2019.
//

#ifndef SEARCHING_GRAPH_H
#define SEARCHING_GRAPH_H

#include <map>
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
    void update_Parent_Child();

private:
    TreeNode* root;
    int depth;
    int total;
    std::map<TreeNode*,TreeNode*>relationships;
};


#endif //SEARCHING_GRAPH_H
