//
// Created by jakeb on 9/24/2019.
//

#ifndef SRC_NODE_H
#define SRC_NODE_H
class Node {

private:
    int data;
    int xposition;
    int yposition;
    Node *next;

public:
    //Deafult constructor
    Node();
    //Constructor that take a value
    Node(int d);
    //Copy constructor
    Node(Node* d);
    //Assignment operator
    Node* operator=(Node*d);
    Node* getNext();
    //Sets the next node
    void setNext(Node *nxt);
    //Gets the previous node
    int& getData();
    //Sets the data of the node
    void setData(int& d);




};
#endif //SRC_NODE_H
