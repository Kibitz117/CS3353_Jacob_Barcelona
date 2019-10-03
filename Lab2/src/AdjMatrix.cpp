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
            Node<int>new_Node=new Node<int>(0);
            edges[i][j]=new_Node;
        }
    }
    visited=new bool[size];



}
bool* AdjMatrix::getVisited() {
    return this->visited;
}
void AdjMatrix::addNode(int src,int dest) {
    this->edges[src-1][dest-1].setData(dest);
}
int AdjMatrix::getSize() {
    return this->numVerticies;
}
Node<int>** AdjMatrix::getVertices() {
    return edges;
}
void AdjMatrix::toString() {
    for (int i = 0; i < this->numVerticies; i++) {
        std::cout << i+1 << " : ";
        for (int j = 0; j < this->numVerticies; j++)
            std::cout << this->edges[i][j].getData() << " ";
        std::cout << "\n";
    }
}
Node<int>* AdjMatrix::Find(int src ,int dest) {
    return &this->edges[src][dest];
}
Node<int> AdjMatrix::getSrc(int src) {
    return src;
}
std::vector<Node<int>*> AdjMatrix::getCons(int row) {
    std::vector<Node<int>*>connections;
    for(int i=0;i<this->numVerticies;i++)
    {
        if(this->edges[row][i].getData()>0)
        {
            connections.push_back(&this->edges[row][i]);
        }
    }
    return connections;
}