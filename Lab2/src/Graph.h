//
// Created by jakeb on 9/25/2019.
//

#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include "LinkedList.h"
class Graph {
public:
    virtual void addNode(int,int)=0;
    virtual int Find(int,int)=0;
    virtual int getSize()=0;

    
private:

};


#endif //SRC_GRAPH_H
