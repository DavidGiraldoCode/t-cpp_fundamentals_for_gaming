// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "LinkedList.h"

int main(int argc, char *argv[])
{
    LinkedList<int> myLinkedList = LinkedList<int>(); // Stack allocated
    // LinkedList<int> *myLinkedListPointer = new LinkedList<int>(); // Heap allocated

    myLinkedList.addFirst(69);
    myLinkedList.addFirst(9);
    myLinkedList.addFirst(6);
    myLinkedList.addLast(1);

    LinkedList<int> myLinkedListCopy = LinkedList<int>(myLinkedList);
    // myLinkedList = LinkedList<int>(myLinkedList);

    myLinkedList.addFirst(77);
    myLinkedListCopy.addFirst(77);

    std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
    std::cout << "myLinkedListCopy.getFirst(): " << myLinkedListCopy.getFirst() << "\n";

    return 0;
}

// std::cout << "SList Size: " << myLinkedList.size() << "\n";
//  std::cout << "HList Size: " << myLinkedListPointer->size() << "\n";
// std::cout << "SList isEmpty: " << myLinkedList.isEmpty() << "\n";
//  std::cout << "HList isEmpty: " << myLinkedListPointer->isEmpty() << "\n";

// try
// {
// Stack allocated
// std::cout << "myLinkedList.removeFirst(): " << myLinkedList.removeFirst() << "\n";
// int &val = myLinkedList.getLast();
// myLinkedList.getFirst() = 5;
// myLinkedList.get(0) = 99;
// val = 2;
// std::cout << "New value? " << myLinkedList.getFirst() << "\n";
// }
// catch (std::exception &exp)
// {
//     std::cout << "Sorry: " << exp.what() << "\n";
// }

// std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
// myLinkedList.addFirst(6);
// std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
// std::cout << "myLinkedList.getLast(): " << myLinkedList.getLast() << "\n";

// myLinkedListPointer->addFirst(1);
// myLinkedListPointer->addFirst(3);

// std::cout << "SList Size: " << myLinkedList.size() << "\n";
// std::cout << "HList Size: " << myLinkedListPointer->size() << "\n";

// std::cout << "HList isEmpty: " << myLinkedListPointer->isEmpty() << "\n";

// std::cout << "myLinkedList.getFirst(): " << myLinkedList.getFirst() << "\n";
// std::cout << "myLinkedList.getLast(): " << myLinkedList.getLast() << "\n";
//  std::cout << "myLinkedList.removeFirst(): " << myLinkedList.removeFirst() << "\n";
// try
// {
// std::cout << "myLinkedList.get(#): " << myLinkedList.get(0) << "\n";
// std::cout << "myLinkedList.removeLast(): " << myLinkedList.removeLast() << "\n";
// std::cout << "myLinkedList.getLast(): " << myLinkedList.getLast() << "\n";
// }
// catch (std::exception &exp)
// {
// std::cout << "Sorry: " << exp.what() << "\n";
// }

// std::cout << "SList Size: " << myLinkedList.size() << "\n";
// myLinkedList.clear();
// std::cout << "SList isEmpty: " << myLinkedList.isEmpty() << "\n";

// std::cout << "myLinkedList.get(#): " << myLinkedList.get(-1) << "\n";

// delete myLinkedListPointer;