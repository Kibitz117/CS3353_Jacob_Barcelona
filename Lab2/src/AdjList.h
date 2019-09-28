//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_ADJLIST_H
#define SRC_ADJLIST_H

#include <algorithm>
#include <vector>
#include "LinkedList.h"
#include "Graph.h"
struct AdjNode{
public:
    LinkedList* potential_paths;
    Node* adj_Node;
    bool operator==(const AdjNode &rhs) {
        if(this->adj_Node->data==rhs.adj_Node->data)
        {
            return true;
        }
        return false;
    }
};
class AdjList: public Graph {
public:
    AdjList(int);
    virtual void addNode(int,int list_Row);
    void add_Edge(int);
    std::vector<AdjNode*> getList();
    AdjNode&operator==(AdjNode&rhs);

private:
    std::vector<AdjNode*>list_Graph;
    int numVerticies;
};


#endif //SRC_ADJLIST_H
