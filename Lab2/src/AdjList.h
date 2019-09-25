//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_ADJLIST_H
#define SRC_ADJLIST_H

#include <vector>
#include "LinkedList.h"
struct AdjNode{
    int data;
public:
    LinkedList* potential_paths;
    Node* adj_Node;
};
class AdjList {
public:
    void add_Node(int,int list_Row);
    void add_Edge(AdjNode*);
    std::vector<AdjNode*> getList();

private:
    std::vector<AdjNode*>list_Graph;
};


#endif //SRC_ADJLIST_H
