//
// Created by jakeb on 9/25/2019.
//

#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include "LinkedList.h"
#include <vector>
class Graph {
public:
    virtual void addNode(int,int,int)=0;
    virtual Node<int>* Find(int,int)=0;
    virtual int getSize()=0;
    virtual std::vector<Node<int>*>getCons(int)=0;

    
private:

};


#endif //SRC_GRAPH_H
