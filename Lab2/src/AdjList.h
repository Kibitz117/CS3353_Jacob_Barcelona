//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_ADJLIST_H
#define SRC_ADJLIST_H

#include <algorithm>
#include <vector>
#include "LinkedList.h"
#include "Graph.h"
#include "AdjNode.h"
template <typename T>
class AdjList: public Graph {
    public:
        AdjList(int);
        virtual void addNode(T,T);
        virtual int Find(int,int);
        LinkedList<AdjNode<T>>& getList();
        virtual int getSize();
        void toString();

    private:
        LinkedList<AdjNode<T>>data;
        int numVerticies;
    };

template <typename T>
AdjList<T>::AdjList(int size) {
    this->numVerticies=size;

}
    template<typename T>
    void AdjList<T>::addNode(T root,T edge)
    {
        AdjNode<T> target;
        target.getNode().setData(root);
        if(data.search(target)<0)
        {
            data.addToTail(target);
            data[data.search(target)].getEdges().addToTail(edge);
        }
        else
            //Erases the values
            data[data.search(target)].getEdges().addToTail(edge);


    }
    template<typename T>
    int AdjList<T>::Find(int src,int dest)
    {
        AdjNode<T> root(src);
        return data[src].getEdges().search(dest);

    }
    template<typename T>
    LinkedList<AdjNode<T>>& AdjList<T>::getList()
    {
        return data;
    }
template <typename T>
int AdjList<T>::getSize() {
    return numVerticies;
}
template <typename T>
void AdjList<T>::toString() {
        for(int i=0;i<numVerticies;i++)
    {
        std::cout<<data[i].getNode().getData()<<": ";
        for(int z=0;z<data[i].getEdges().getSize();z++)
        {
            std::cout<<data[i].getEdges().operator[](z)<<" ";
        }
        std::cout<<std::endl;
    }
}
#endif //SRC_ADJLIST_H
