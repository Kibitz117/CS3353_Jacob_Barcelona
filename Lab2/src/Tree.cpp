////
//// Created by jakeb on 9/22/2019.
////
//
//#include "Tree.h"
//Tree::Tree() {
//root=nullptr;
//depth=0;
//total=0;
//}
//Tree::Tree(int r) {
//    TreeNode root_Node;
//    root_Node.data = r;
//    root = &root_Node;
//    depth = 0;
//    total = 1;
//    relationship.emplace_back(std::make_pair(root_Node,root_Node));
//}
//
//TreeNode* Tree::find(int data) {
//    if(root->data==data)
//    {
//        return root;
//    }
//    else
//    {
//        TreeNode* current=root;
//        while(!current->data==data)
//        {
//
//        }
//    }
//}
//void Tree::insertNode(TreeNode*new_Node) {
//        relationships.insert(new_Node->parent,new_Node);
//        relationship.emplace_back(std::make_pair(new_Node->parent,new_Node));
//        total++;
//
//
//}
////Returns vector of children
//std::vector<TreeNode*> Tree::getChildren(TreeNode*par) {
//    return par->children;
//}
//void Tree::deleteTree() {
//    delete root;
//}