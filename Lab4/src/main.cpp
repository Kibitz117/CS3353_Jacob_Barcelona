#include <iostream>
#include "Search.h"
int main() {
    Algorithm* a=new Search();
    a->Load("positions.txt",0);
    for(int i=4;i<15;i++)
    {
        a->Configure(i);
        a->Select(2);
        a->Execute(1);
        a->Stats(2);
    }

//    for(int i=2;i<=3;i++)
//    {
//        a->Select(i);
//        a->Execute(1);
//        a->Stats(i);
//    }
    return 0;
}