//////
////// Created by jakeb on 9/22/2019.
//////
////
#ifndef SEARCHING_GRAPH_H
#define SEARCHING_GRAPH_H

#include "LinkedList.h"
#include <map>
#include <vector>
#include <math.h>
struct TreeNode{
    int data=0;
    double weight=0.0;
    std::vector<int> position;
    double distance_parent=0.0;
    struct TreeNode* parent= nullptr;
    std::vector<TreeNode*>children;
    bool visited=false;
    double cost=(1+weight)*(distance_parent);



};
//Resets root
class Tree {
public:
    Tree();
    Tree(int);
    ~Tree();
    std::vector<TreeNode*> getChildren(struct TreeNode*);
    void insertNode(TreeNode*,int,double,std::vector<int>&);
    void deleteNode(TreeNode*);
    struct TreeNode* find(int);
    TreeNode* getParent(TreeNode*);
    void setParent(int);
    TreeNode* getLeaves(int);
    TreeNode* getRoot();
    std::vector<TreeNode*>SavePath(int);
   static void setWeight(TreeNode&,double);
   static void setPosition(TreeNode&);
   int getShortest(int);
   int getTotal();


private:
    TreeNode* root;
    int depth;
    int total;
    std::map<int,TreeNode*>leaves;
};


#endif //SEARCHING_GRAPH_H
