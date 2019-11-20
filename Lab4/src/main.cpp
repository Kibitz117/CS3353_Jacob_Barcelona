#include <iostream>
#include "Search.h"
//SCREW NODE MAP JUST MAKE CITYS LIKE THE JAVA EXAMPLE
int main() {
    Algorithm* a=new Search();
    a->Load("positions.txt",0);
    a->Execute(1);
    return 0;
}