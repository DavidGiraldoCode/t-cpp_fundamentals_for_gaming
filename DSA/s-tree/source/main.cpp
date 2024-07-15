// g++ -std=c++20 *.cpp -o MyProgram && ./MyProgram
#include <iostream>
#include "Tree.h"
#include "Warrior.h"

int main(int argc, char* agrv[])
{
    Tree<int> tree = Tree<int>();
    Warrior myWarrrior = Warrior();
    std::cout << "Ready!\n";
};