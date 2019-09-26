//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_LINKEDLIST_H
#define SRC_LINKEDLIST_H
#include <stdio.h>
#include <iostream>
#include <stdexcept>
struct Node{
    Node *next;
    Node *prev;
public:
    int data;
    bool visited;
};
class LinkedList{

public:
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList&);
    void addToTail(int data);
    void addToHead(int data);
    void insert(int data,int position);
    //Asignment operator
    Node* operator[](int)const;
    LinkedList& operator=(const LinkedList&);
    int search(int&val);
    int getSize();
private:
    Node *head;
    Node *tail;
    int size;
};


#endif //SRC_LINKEDLIST_H
