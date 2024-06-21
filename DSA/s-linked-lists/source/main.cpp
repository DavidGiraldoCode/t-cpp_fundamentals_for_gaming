// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList<int> myLinkedList = LinkedList<int>();             // Stack allocated
    LinkedList<int> *myLinkedListPointer = new LinkedList<int>(); // Heap allocated

    std::cout << "SList Size: " << myLinkedList.size() << "\n";
    std::cout << "HList Size: " <<myLinkedListPointer->size() << "\n";

    myLinkedList.addFirst(1);

    std::cout << "SList isEmpty: " << myLinkedList.isEmpty() << "\n";
    std::cout << "HList isEmpty: " << myLinkedListPointer->isEmpty() << "\n";

    delete myLinkedListPointer;

    return 0;
}