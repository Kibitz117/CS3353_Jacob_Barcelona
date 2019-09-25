//
// Created by jakeb on 9/25/2019.
//

#include "LinkedList.h"
//Deafult constructor
LinkedList::LinkedList()
{
    head=nullptr;
    tail=nullptr;
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
            erase=temp->next;
            delete temp;
            temp=erase;
        }
    }
}
//Copy Constructor
LinkedList::LinkedList(const LinkedList&rhs)
{

    head=tail=nullptr;
    size=0;
    Node*current=rhs.head;
    while(current!=nullptr)
    {
        this->addToTail(current->data);
        current=current->next;
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
        Node *nodey;
        nodey->data=data;
        previous->next = nodey;
        nodey->next=current;
        nodey->prev=previous;
        current->prev=nodey;
    }





}

//Adds node at the tail of the linked list
void LinkedList::addToTail(int data)
{
    Node*temp;
    temp->data=data;
    if(head==nullptr)
    {
        head=temp;
        tail=head;
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
        Node* newNode;
        newNode->data=data;
        head=newNode;
        tail=head;
    }
    else
    {
        Node *newNode;
        newNode->data=data;
        head->prev = newNode;
        head->prev->next=head;
        head=head->prev;
    }
    size++;
}
int LinkedList::getSize() {
    return size;
}
//Finds the node of the value that is passed into the search function
int LinkedList::search(int& val)
{
    int counter=0;
    Node*curr=head;
    while(curr!=nullptr){

        if(curr->data==val)
        {
            return counter;
        }
        counter++;
        curr=curr->next;
    }

    return -1;
}
//Accesses the data at a specific position of the linked list
Node& LinkedList::operator[](int pos)const
{
    //if pos>size
    Node*current=head;
    while(current!=nullptr&&pos>0)
    {
        current=current->next;
        pos--;
    }
    if(current!=nullptr)
    {
        return current->data;
    }
    throw std::out_of_range("Uh oh ya went out of range ¯\_(ツ)_/¯");
}