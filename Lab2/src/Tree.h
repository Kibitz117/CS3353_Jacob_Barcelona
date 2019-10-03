//////
////// Created by jakeb on 9/22/2019.
//////
////
#ifndef SEARCHING_GRAPH_H
#define SEARCHING_GRAPH_H

#include "LinkedList.h"
#include <map>
#include <vector>
struct TreeNode{
    int data=0;
    int weight=0;
    int position=0;
    int distance_parent=0;
    struct TreeNode* parent= nullptr;
    std::vector<TreeNode*>children;
    bool visited=false;

};
//Resets root
class Tree {
public:
    Tree();
    Tree(int);
    std::vector<TreeNode*> getChildren(struct TreeNode*);
    void insertNode(struct TreeNode*);
    void deleteTree();
    struct TreeNode* find(int);
    TreeNode* getParent(TreeNode*);
    void setParent(int);
    TreeNode* getLeaves(int);
    TreeNode* getRoot();
    std::vector<TreeNode*>SavePath(int);


private:
    TreeNode* root;
    int depth;
    int total;
    std::map<int,TreeNode*>leaves;
};


#endif //SEARCHING_GRAPH_H
