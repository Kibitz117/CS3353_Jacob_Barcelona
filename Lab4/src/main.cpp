#include <iostream>
#include "Search.h"
//ASK CLARK ABOUT DYNAMIC BRUTE FORCE VS TABU GA TIMING EG(STOP AT RIGHT COST?) HOW TO ALSO CHECK IF GRAPHS GOOD? LEARNING CURVES SUFFICIENT?
int main() {
    Algorithm* a=new Search();
    a->Load("largePositions(2).txt",0);
//    for(int i=4;i<=11;i++)
//    {
//        a->Configure(i);
//        a->Select(3);
//        a->Execute(1);
//        a->Stats(3);
//    }
    a->Configure(100);
        a->Select(2);
        a->Execute(1);
        a->Stats(2);



//    for(int i=2;i<=3;i++)
//    {
//        a->Select(i);
//        a->Execute(1);
//        a->Stats(i);
//    }
    return 0;
}