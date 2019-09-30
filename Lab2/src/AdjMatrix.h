//
// Created by jakeb on 9/25/2019.
//

#ifndef SRC_ADJMATRIX_H
#define SRC_ADJMATRIX_H

#include "LinkedList.h"
#include <vector>
#include "Graph.h"
#include "Node.h"
class AdjMatrix: public Graph {
public:
    AdjMatrix(int);
    void addNode(int x,int y);
    int getNumVerticies();
    Node<int>**getVertices();
    void toString();
    int Find(int);
private:
    Node<int>**edges;
    int numVerticies;

};


#endif //SRC_ADJMATRIX_H
