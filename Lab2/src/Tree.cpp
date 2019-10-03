//////
////// Created by jakeb on 9/22/2019.
//////
////
#include "Tree.h"
Tree::Tree() {
root=nullptr;
depth=0;
total=0;
}
Tree::Tree(int r) {
    TreeNode *root_Node=new TreeNode();
    root_Node->data = r;
    root_Node->parent=nullptr;
    root = root_Node;
    depth = 0;
    total = 1;
    this->leaves.insert(std::make_pair(root->data,root));
}
void Tree::insertNode(TreeNode*new_Node) {
    //Update leaf pointers
    std::map<int,TreeNode*>::iterator it = leaves.find(new_Node->data);
    if(it==leaves.end())
    {
        leaves[new_Node->data]=new_Node;
        //Remove parent from leaf node pointers
        std::map<int,TreeNode*>::iterator iter=leaves.find(new_Node->parent->data);
        if(iter!=leaves.end())
            leaves.erase(new_Node->parent->data);
        //This line isn't working properly
        //Push back new Node to its parent's vector of children
        new_Node->parent->children.push_back(new_Node);
        total++;
        if(new_Node->parent->children.size()<2)
        {
            depth++;
        }

    }


}
//Returns vector of children
std::vector<TreeNode*> Tree::getChildren(TreeNode*par) {
    return par->children;
}
void Tree::deleteTree() {
    delete root;
}
TreeNode* Tree::getLeaves(int i) {
        return leaves[i];
}
TreeNode* Tree::getParent(TreeNode *curr) {
    return curr->parent;
}
TreeNode* Tree::getRoot() {
    return root;
}
std::vector<TreeNode*> Tree::SavePath(int dest) {
    std::vector<TreeNode*>path;
    TreeNode*curr=leaves[dest];
    while(curr!=root)
    {
        path.push_back(curr);
        curr=curr->parent;
    }
    return path;

}
//Map of leaf nodes