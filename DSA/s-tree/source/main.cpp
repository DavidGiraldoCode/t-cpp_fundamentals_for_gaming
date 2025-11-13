// g++ -std=c++20 *.cpp -o MyProgram && ./MyProgram
#include <iostream>
#include "Tree.h"
#include "Warrior.h"

int main(int argc, char *agrv[])
{
    Tree<Warrior> tree = Tree<Warrior>();
    std::vector<Warrior> army = {
        Warrior('Z', 8),
        Warrior('B', 9),
        Warrior('C', 5),
        Warrior('B', 6)};
    for (size_t i = 0; i < army.size(); i++)
    {
        std::cout << "In army: " << army[i];
    }
    tree.insert(army[0]);
    tree.insert(army[1]);
    tree.insert(army[0]);
    tree.insert(army[3]);
    tree.insert(army[2]);
    tree.insert(army[2]);
    std::cout << tree.toString() << '\n';
};