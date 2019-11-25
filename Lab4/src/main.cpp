#include <iostream>
#include "Search.h"
int main() {
    Algorithm* a=new Search();
    a->Load("positions.txt",0);
    a->Select(2);
    a->Execute(1);
    a->Stats(2);
    return 0;
}