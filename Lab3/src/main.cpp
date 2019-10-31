#include <iostream>
#include "FileLoader.h"
#include "Search.h"

int main() {
   // FileLoader::load("C:\\Algorithms\\Lab3\\src\\cmake-build-debug\\positions.txt",0);
   Search s;
   s.Load("C:\\Algorithms\\Lab3\\src\\cmake-build-debug\\positions.txt",0);
   s.Select(0);
   s.Execute(1);

    return 0;
}