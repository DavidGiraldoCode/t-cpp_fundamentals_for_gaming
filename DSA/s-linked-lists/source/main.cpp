// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList<int> myLinkedList = LinkedList<int>();             // Stack allocated
    LinkedList<int> *myLinkedListPointer = new LinkedList<int>(); // Heap allocated

    std::cout << "SList Size: " << myLinkedList.size() << "\n";
    // std::cout << "HList Size: " << myLinkedListPointer->size() << "\n";
    std::cout << "SList isEmpty: " << myLinkedList.isEmpty() << "\n";
    // std::cout << "HList isEmpty: " << myLinkedListPointer->isEmpty() << "\n";

    try
    {
        std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
    }
    catch (std::exception &exp)
    {
        std::cout << "Sorry: " << exp.what() << "\n";
    }

    // std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
    // myLinkedList.addFirst(6);
    // std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
    // std::cout << "myLinkedList.getLast(): " << myLinkedList.getLast() << "\n";

    // myLinkedListPointer->addFirst(1);
    // myLinkedListPointer->addFirst(3);

    // std::cout << "SList Size: " << myLinkedList.size() << "\n";
    // std::cout << "HList Size: " << myLinkedListPointer->size() << "\n";

    // std::cout << "HList isEmpty: " << myLinkedListPointer->isEmpty() << "\n";

    myLinkedList.addLast(7);
    std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
    std::cout << "myLinkedList.getLast(): " << myLinkedList.getLast() << "\n";
    // std::cout << "myLinkedList.removeFirst(): " << myLinkedList.removeFirst() << "\n";
    try
    {
        std::cout << "myLinkedList.get(#): " << myLinkedList.get(1) << "\n";
    }
    catch (std::exception exp)
    {
        std::cout << "Sorry: " << exp.what() << "\n";
    }

    // std::cout << "SList Size: " << myLinkedList.size() << "\n";
    myLinkedList.clear();
    std::cout << "SList isEmpty: " << myLinkedList.isEmpty() << "\n";

    // std::cout << "myLinkedList.get(#): " << myLinkedList.get(-1) << "\n";

    delete myLinkedListPointer;

    return 0;
}