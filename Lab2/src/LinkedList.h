//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_LINKEDLIST_H
#define SRC_LINKEDLIST_H
#include <stdio.h>
#include "node.h"
#include <iostream>
#include <stdexcept>

class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&);
    void addToTail(int data);
    void addToHead(int data);
    void insert(int data,int position);
    //Asignment operator
    int& operator[](int)const;
    LinkedList& operator=(const LinkedList&);
private:
    Node *head;
    Node *tail;
    Node *iter;//reset returns iterator to head and getnext returns value of next element methods for iterator
    int size;
};


#endif //SRC_LINKEDLIST_H
