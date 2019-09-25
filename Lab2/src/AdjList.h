//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_ADJLIST_H
#define SRC_ADJLIST_H

#include <vector>
#include "LinkedList.h"
#include "Node.h"
class AdjList {
public:
    void add_Node(int,int list_Row);
    void add_Edge(LinkedList<int>*);
private:
    std::vector<LinkedList<int>>adjacency_graph;
};


#endif //SRC_ADJLIST_H
