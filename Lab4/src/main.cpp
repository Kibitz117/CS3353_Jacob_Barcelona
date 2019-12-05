#include <iostream>
#include "Search.h"
//ASK CLARK ABOUT DYNAMIC BRUTE FORCE VS TABU GA TIMING EG(STOP AT RIGHT COST?) HOW TO ALSO CHECK IF GRAPHS GOOD? LEARNING CURVES SUFFICIENT?
int main() {
    Algorithm* a=new Search();
    a->Load("largePositions(2).txt",0);
    //Size of graph
        a->Configure(100);
        a->Select(2);
        //Number of iterations
        a->Execute(40);
        a->Stats(2);
        //Size of graph
    a->Configure(100);
    a->Select(3);
    //Number of iterations
    a->Execute(30);
    a->Stats(3);
//    for(int i=2;i<=3;i++)
//    {
//        a->Select(i);
//        a->Execute(1);
//        a->Stats(i);
//    }
    return 0;
}