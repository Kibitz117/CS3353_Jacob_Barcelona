//
// Created by jakeb on 9/25/2019.
//

#ifndef SRC_ADJMATRIX_H
#define SRC_ADJMATRIX_H

#include "LinkedList.h"
#include <vector>
#include "Graph.h"
class AdjMatrix: public Graph {
public:
    void addNode(int x,int y,struct Node*);
private:
    std::vector<std::vector<Node*>>edges;
    int numVerticies;

};


#endif //SRC_ADJMATRIX_H
