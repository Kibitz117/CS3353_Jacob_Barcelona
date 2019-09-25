//
// Created by jakeb on 9/24/2019.
//
#include "Node.h"
Node::Node()
{
next=nullptr;
}
//Constructor that take a value
Node::Node(int d)
{
data=d;
next=nullptr;
}
//Copy constructor
Node::Node(Node* d)
{
if(d==nullptr)
{

}else{
this->data=d->data;
}
next=nullptr;
}
//Assignment operator
Node* Node::operator=(Node*d)
{
    data=d->data;
    next=d->next;
    return this;
}



Node* Node::getNext(){
    return next;
}
//Sets the next node
void Node::setNext(Node *nxt)
{
    next=nxt;
}
//Gets the value of the node
int& Node::getData()
{
    return data;
}
//Sets the data of the node
void Node::setData(int& d)
{
   data=d;
}
