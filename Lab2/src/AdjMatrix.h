//
// Created by jakeb on 9/25/2019.
//

#ifndef SRC_ADJMATRIX_H
#define SRC_ADJMATRIX_H


class AdjMatrix {
public:
    void addNode(int x,int y,struct Node*);
private:
    struct Node* matrix_graph[5][6];
};


#endif //SRC_ADJMATRIX_H
