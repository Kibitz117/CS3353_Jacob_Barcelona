//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_LINKEDLIST_H
#define SRC_LINKEDLIST_H
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include "Node.h"
#include <iostream>
#include <stdexcept>
template <typename T>
class LinkedList{
    template <class U> friend class myStack;
public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T>&);
    void addToTail(T data);
    void addToHead(T data);
    void insert(T data,int position);
    void remove (int position);
    void display();
    int search(T& val);
    int getSize();
    void resetIter();
    bool iterValid();
    T& getIter();
    void stepIter();
    bool isEmpty();

    //Asignment operator

    T& operator[](int)const;
    LinkedList<T>& operator=(const LinkedList<T>&);
private:
    Node<T> *head;
    Node<T> *tail;
    Node<T> *iter;//reset returns iterator to head and getnext returns value of next element methods for iterator
    int size;
};
template <typename T>
//Deafult constructor
LinkedList<T>::LinkedList()
{
    head=nullptr;
    tail=nullptr;
    iter=nullptr;
    size=0;
}
template <typename T>
//Destructor
LinkedList<T>::~LinkedList()
{
    if(head!=nullptr)
    {
        Node<T>* temp=head;
        Node<T>* erase;
        while(temp!=nullptr)
        {
            erase=temp->next;
            delete temp;
            temp=erase;
        }
    }
}
template <typename T>
//Copy Constructor
LinkedList<T>::LinkedList(const LinkedList<T>&rhs)
{

    head=tail=iter=nullptr;
    size=0;
    Node<T>*current=rhs.head;
    while(current!=nullptr)
    {
        this->addToTail(current->data);
        current=current->next;
    }


}
template <typename T>
//Assigns this to a linked list taken in from the parameters and copys over the data
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>&rhs)
{
    if(!(this==&rhs))
    {
        Node<T>* temp;
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

template <typename T>
//Inserts a node a a specific spot in the linked list
void LinkedList<T>::insert(T data,int position)
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
        Node<T>* current=head;
        Node<T> *previous;
        Node<T> *nextnode;
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
template <typename T>
//removes a node at a certain position
void LinkedList<T>::remove(int position)
{
    Node<T> *current=head;
    Node<T> *previous;
    Node<T> *nextNode;
    int count=0;
    //Checks if linked list if empty
    if(head==nullptr||tail==nullptr)
    {
        return;
    }
        //Checks if node to be removed is head
    else if (position == 0) {
        head=head->next;
        if(head!=nullptr)
            head->prev=nullptr;
        delete current;
    }
    else if(position==this->getSize()-1)
    {
        tail=tail->prev;
        delete tail->next;
        tail->next=nullptr;
    }
        //Else iterate through list and remove node at position
    else{
        while(count<position&&current!=nullptr)
        {

            previous=current;
            current=current->next;
            nextNode=current->next;
            count++;
        }


        previous->next = nextNode;
        nextNode->prev=previous;
        delete current;
    }
    size--;

}
template <typename T>
//Adds node at the tail of the linked list
void LinkedList<T>::addToTail(T data)
{
    Node<T>*temp=new Node<T>(data);
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
template <typename T>
//Adds node at the head of the linked list
void LinkedList<T>::addToHead(T data)
{
    //Checks if linked list if empty
    if(head==nullptr||tail==nullptr)
    {
        head=new Node<T>(data);
        tail=head;
        iter=head;
    }
    else
    {
        Node<T> *newNode=new Node<T>(data);
        head->prev = newNode;
        head->prev->next=head;
        head=head->prev;
    }
    size++;
}
template <typename T>
//returns the size of a linked list
int LinkedList<T>::getSize()
{
    return size;
}
template <typename T>
//displays the linked list
void LinkedList<T>::display()
{
    Node<T> * current = head;
    if (current == nullptr)
        std::cout << "Link List is empty" << std::endl;
    else
        // iterate over the list and display each value
    { while(current != nullptr)
        {
            std::cout << current->getData() << std::endl;
            current = current->next;
        } // end of while loop
    }
}
template <typename T>
//Accesses the data at a specific position of the linked list
T& LinkedList<T>::operator[](int pos)const
{
    //if pos>size
    Node<T>*current=head;
    while(current!=nullptr&&pos>0)
    {
        current=current->next;
        pos--;
    }
    if(current!=nullptr)
    {
        return current->data;
    }
    throw std::out_of_range("Uh oh ya went out of range");
}
template <typename T>
//Reserts the iterator back to head
void LinkedList<T>::resetIter()
{
    iter=head;
}
template <typename T>
//Checks if the iterator isn't a nullptr
bool LinkedList<T>::iterValid()
{
    return iter!=nullptr;
}
template <typename T>
//Gets the data from the iterator
T& LinkedList<T>::getIter()
{
    if(iter==nullptr)
        throw std::out_of_range("Uh oh ya went out of range");
    return iter->data;
}
template <typename T>
//Moves the iterator to the next element in the linked list
void LinkedList<T>::stepIter()
{
    iter=iter->next;
}
template <typename T>
//Finds the node of the value that is passed into the search function
int LinkedList<T>::search(T& val)
{
    int counter=0;
    Node<T>*curr=head;
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
template <typename T>
//Checks if the linked list is empty, returns true is empty
bool LinkedList<T>::isEmpty()
{
    if(size==0||head==nullptr)
    {
        return true;
    }
    return false;
}


#endif //SRC_LINKEDLIST_H
