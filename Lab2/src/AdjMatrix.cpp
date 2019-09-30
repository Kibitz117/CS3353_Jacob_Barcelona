//
// Created by jakeb on 9/25/2019.
//

#include "AdjMatrix.h"
AdjMatrix::AdjMatrix(int size) {
    this->numVerticies=size;
    this->edges=new Node<int>*[size];
    for(int i=0;i<size;i++)
    {
        this->edges[i]=new Node<int>[size];
        for(int j=0;j<size;j++)
        {
            Node<int>new_Node;
            edges[i][j]=new_Node;
        }
    }



}
void AdjMatrix::addNode(int src,int dest) {
    //this->edges[src-1][dest-1]=new Node<int>(dest);
    this->edges[src-1][dest-1].setData(dest);
}
int AdjMatrix::getNumVerticies() {
    return this->numVerticies;
}
Node<int>** AdjMatrix::getVertices() {
    return edges;
}
void AdjMatrix::toString() {
    for (int i = 0; i < this->numVerticies; i++) {
        std::cout << i << " : ";
        int numVertices;
        for (int j = 0; j < numVertices; j++)
            std::cout << this->edges[i][j].getData() << " ";
        std::cout << "\n";
    }
}
int AdjMatrix::Find(int) {
    return 0;
}