//
// Created by jakeb on 9/28/2019.
//

#ifndef SRC_ADJNODE_H
#define SRC_ADJNODE_H

#include "linkedlist.h"
#include "node.h"
template <typename T>
class AdjNode{
    template <class U> friend class AdjList;
public:
    AdjNode();
    AdjNode(T);
    bool operator==(AdjNode<T>&);
    LinkedList<T>&getEdges();
    Node<T>&getNode();
private:
    LinkedList<T>edges;
    Node<T> nodey;
};
template<typename T>
AdjNode<T>::AdjNode()
{

}
template<typename T>
AdjNode<T>::AdjNode(T data){
    nodey.getData()=data;
}
template<typename T>
bool AdjNode<T>::operator== (AdjNode<T>& nodey2)
{
    if(nodey.getData()==(nodey2.getNode()).getData())
    {
        return true;
    }
    return false;
}
template<typename T>
LinkedList<T>& AdjNode<T>::getEdges()
{
    return edges;
}
template<typename T>
Node<T>& AdjNode<T>::getNode()
{
    return nodey;
}


#endif //SRC_ADJNODE_H
