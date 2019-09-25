//
// Created by jakeb on 9/25/2019.
//

#include "LinkedList.h"
//Deafult constructor
LinkedList::LinkedList()
{
    head=nullptr;
    tail=nullptr;
    iter=nullptr;
    size=0;
}
//Destructor
LinkedList::~LinkedList()
{
    if(head!=nullptr)
    {
        Node* temp=head;
        Node* erase;
        while(temp!=nullptr)
        {
            erase=temp->getNext();
            delete temp;
            temp=erase;
        }
    }
}
//Copy Constructor
LinkedList::LinkedList(const LinkedList&rhs)
{

    head=tail=iter=nullptr;
    size=0;
    Node*current=rhs.head;
    while(current!=nullptr)
    {
        this->addToTail(current->getData());
        current=current->getNext();
    }


}
//Assigns this to a linked list taken in from the parameters and copys over the data
LinkedList& LinkedList::operator=(const LinkedList&rhs)
{
    if(!(this==&rhs))
    {
        Node* temp;
        if(head!=nullptr||tail!=nullptr)
        {
            temp=head;
            while(temp->next!=nullptr)
            {
                head=head->next;
                delete temp;
                temp=head;
            }
        }

        temp=rhs.head;
        while(temp!=nullptr)
        {
            this->addToTail(temp->data);
            temp=temp->next;
        }
        size=rhs.size;
    }
    return *this;
}
//Inserts a node a a specific spot in the linked list
void LinkedList::insert(int data,int position)
{
    //Checks if head
    if(position==0)
    {
        this->addToHead(data);
    }
        //Checks if tail
    else if(position==size-1)
    {
        this->addToTail(data);
    }
    else
    {
        Node* current=head;
        Node *previous;
        Node *nextnode;
        int count=0;
        //Loops until spot for insert is found
        while(current!=nullptr&&count!=position)
        {
            previous=current;
            current=current->next;
            nextnode=current->next;
            count++;
        }
        Node<T> *nodey=new Node<T>(data);
        previous->next = nodey;
        nodey->next=current;
        nodey->prev=previous;
        current->prev=nodey;
    }





}

//Adds node at the tail of the linked list
void LinkedList::addToTail(int data)
{
    Node*temp=new Node(data);
    if(head==nullptr)
    {
        head=temp;
        tail=head;
        iter=head;
    }
    else{
        tail->next=temp;
        tail->next->prev=tail;
        tail=tail->next;
        tail->next=nullptr;
    }
    size++;


}
//Adds node at the head of the linked list
void LinkedList::addToHead(int data)
{
    //Checks if linked list if empty
    if(head==nullptr||tail==nullptr)
    {
        head=new Node(data);
        tail=head;
        iter=head;
    }
    else
    {
        Node *newNode=new Node(data);
        head->prev = newNode;
        head->prev->next=head;
        head=head->prev;
    }
    size++;
}
