//
// Created by jakeb on 9/25/2019.
//

#include "AdjMatrix.h"
AdjMatrix::AdjMatrix(int size) {
    this->numVerticies=size;
    this->edges=new Node**[size];
    for(int i=0;i<size;i++)
    {
        this->edges[i]=new Node*[size];
    }
}
void AdjMatrix::addNode(int src,int dest) {
    struct Node* new_Node;
    new_Node->data=dest;
    this->edges[src][dest]=new_Node;
}