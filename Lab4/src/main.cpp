#include <iostream>
#include "Search.h"
int main() {
    Algorithm* a=new Search();
    a->Load("largePositions.txt",0);
//    for(int i=5;i<=40;i+=5)
//    {
//        a->Configure(i);
//        a->Select(2);
//        a->Execute(1);
//        a->Stats(2);
//    }
    a->Configure(50);
        a->Select(3);
        a->Execute(1);
        a->Stats(3);



//    for(int i=2;i<=3;i++)
//    {
//        a->Select(i);
//        a->Execute(1);
//        a->Stats(i);
//    }
    return 0;
}