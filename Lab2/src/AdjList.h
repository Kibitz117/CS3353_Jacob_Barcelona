//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_ADJLIST_H
#define SRC_ADJLIST_H

#include <algorithm>
#include <vector>
#include "LinkedList.h"
#include "Graph.h"
class AdjList: public Graph {
    public:
        AdjList(int);
        virtual void addNode(int,int);
        virtual Node<int>* Find(int,int);
    std::vector<Node<LinkedList<Node<int>>>>&  getList();
        virtual int getSize();
        void toString();
        virtual bool*getVisited();
        virtual std::vector<Node<int>*>getCons(int);

    private:
        std::vector<Node<LinkedList<Node<int>>>>data;
        int numVerticies;
        bool*visited;
    };



#endif //SRC_ADJLIST_H
