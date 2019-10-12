//
// Created by jakeb on 10/2/2019.
//
#include "AdjList.h"
AdjList::AdjList(int size) {
    this->numVerticies=size;
    data.reserve(size);
    Node<LinkedList<Node<int>>>edge;
    for(int i=0;i<size;i++)
    {
        data.push_back(edge);
    }
    visited=new bool[size];


}
bool* AdjList::getVisited() {
    return visited;
}
void AdjList::addNode(int root,int edge)
{
    data[root-1].getData().addToHead(edge);


}

Node<int>* AdjList::Find(int src,int dest)
{
    return &data[src].getData().operator[](dest);

}
std::vector<Node<LinkedList<Node<int>>>>& AdjList::getList()
{
    return data;
}
int AdjList::getSize() {
    return numVerticies;
}
void AdjList::toString() {
    for(int i=0;i<numVerticies;i++)
    {
        std::cout<<i+1<<": ";
        for(int z=0;z<data[i].getData().getSize();z++)
        {
            std::cout<<data[i].getData().operator[](z).getData()<<" ";
        }
        std::cout<<std::endl;
    }
}
std::vector<Node<int>*> AdjList::getCons(int src) {
    src+=1;
    std::vector<Node<int>*>connections;
    Node<LinkedList<Node<int>>> edge=data[src-1];
    for(int i=0;i<edge.getData().getSize();i++)
    {
        if(data[src-1].getData()[i].getData()>0)
            connections.push_back(&data[src-1].getData()[i]);
    }
    return connections;
}