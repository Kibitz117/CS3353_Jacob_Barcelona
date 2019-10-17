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
    ~TreeNode(){
        for(int i=0;i<children.size();i++)
        {
            delete children[i];
        }
    }

};
//Resets root
class Tree {
public:
    Tree();
    Tree(int);
    ~Tree();
    std::vector<TreeNode*> getChildren(struct TreeNode*);
    void insertNode(struct TreeNode*);
    void deleteTree();
    struct TreeNode* find(int);
    TreeNode* getParent(TreeNode*);
    void setParent(int);
    TreeNode* getLeaves(int);
    TreeNode* getRoot();
    std::vector<TreeNode*>SavePath(int);
   static void setWeight(TreeNode&,double);
   static void setPosition(TreeNode&,std::vector<int>);
   int getShortest(int);


private:
    TreeNode* root;
    int depth;
    int total;
    std::map<int,TreeNode*>leaves;
};


#endif //SEARCHING_GRAPH_H
