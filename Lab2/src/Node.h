//
// Created by jakeb on 9/28/2019.
//

#ifndef SRC_NODE_H
#define SRC_NODE_H


template <typename T>
class Node {
    template <class U> friend class LinkedList;

private:
    T data;
    Node<T> *next;
    Node<T> *prev;
    bool visited;
    double weight;
public:
    //Deafult constructor
    Node<T>()
    {
        next=nullptr;
        prev=nullptr;
    }
    //Constructor that take a value
    Node<T>(T d)
    {
        data=d;
        next=nullptr;
        prev=nullptr;
    }
    //Copy constructor
    Node<T>(Node<T>* d)
    {
        if(d==nullptr)
        {

        }else{
            this->data=d->data;
        }
        next=nullptr;
        prev=nullptr;
    }
    //Assignment operator
    Node<T>* operator=(Node<T>*d)
    {
        data=d->data;
        next=d->next;
        prev=d->prev;
        return this;
    }



    Node<T>* getNext(){
        return next;
    }
    //Sets the next node
    void setNext(Node *nxt)
    {
        next=nxt;
    }
    //Gets the previous node
    Node<T>* getPrev()
    {
        return prev;
    }
    //Sets the previos node
    void setPrev(Node *pre)
    {
        prev=pre;
    }
    //Gets the value of the node
    T& getData()
    {
        return data;
    }
    //Sets the data of the node
    void setData(T& d)
    {
        data=d;
    }
    bool isVisited(){
        return visited;
    }
    void setVisited(bool visited)
    {
        this->visited=visited;
    }
    void setWeight(double& weight)
    {
        this->weight=weight;
    }
    double getWeight()const
    {
        return this->weight;
    }



};


#endif //SRC_NODE_H
