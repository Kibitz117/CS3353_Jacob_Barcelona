#include <iostream>
#include "FileLoader.h"
#include "Search.h"

int main() {
    Algorithm*s =new Search();
   s->Load("C:\\Algorithms\\Lab3\\src\\cmake-build-debug\\positions.txt",0);
   for(int i=0;i<2;i++)
   {
       s->Select(i);
       s->Execute(1);
       s->Stats(i);
   }
    delete s;

    return 0;
}