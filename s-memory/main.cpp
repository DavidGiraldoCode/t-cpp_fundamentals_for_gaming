// g++ -std=c++20 main.cpp -o myProgram && ./myProgram
#include <iostream>

void printPointer(const int & ref)
{
    std::cout << &ref << " value: "<< ref << " bytes: " << sizeof(ref) << "\n";
}

int main(int argc, char * argv[])
{
    int a = 5;
    int b = 10;
    int c = 15;

    int badArray[5]; // Demo of a non-initialized variable
    int goodArray[5] = {};

    int * heapArray = new int[5]; //Demo of a dynamically allocated memory

    /* 
    This demostrates that stack memory is linearly allocated

    << OUTPUT
        Address     | Value | bytes
        0x16fdfeebc |  5    |   4
        0x16fdfeeb8 |  10   |   4
        0x16fdfeeb4 |  15   |   4
    */

    std::cout << "I am ready" << "\n";
    printPointer(a);
    printPointer(b);
    printPointer(c);

    std::cout << "\n" << "Non-initialiazed Array" << "\n";
    for (size_t i =0; i < (sizeof(badArray)/sizeof(badArray[0])); i++)
    {
        printPointer(badArray[i]);
    }

    /*
    The array got allocated in the stack memory, but C++ asigned garbage 
    values available at that time in RAM.

    << OUTPUT
        0x16d87ae94 value: 1        bytes: 4
        0x16d87ae98 value: 39393552 bytes: 4
        0x16d87ae9c value: 1        bytes: 4
        0x16d87aea0 value: 39387136 bytes: 4
        0x16d87aea4 value: 1        bytes: 4
    */

   std::cout << "\n" << "Properly initialiazed Array" << "\n";
   for (size_t i =0; i < (sizeof(goodArray)/sizeof(goodArray[0])); i++)
    {
        printPointer(goodArray[i]);
    }
    /*
    All values were initialized with a known value
    << OUTPUT
        0x16cf16e80 value: 0 bytes: 4
        0x16cf16e84 value: 0 bytes: 4
        0x16cf16e88 value: 0 bytes: 4
        0x16cf16e8c value: 0 bytes: 4
        0x16cf16e90 value: 0 bytes: 4
    */

   std::cout << "\n" << "Heap memory Array" << "\n";
   for (size_t i =0; i < 5; i++)
    {
        printPointer(heapArray[i]); 
    }
    /*
    In this Heap memory Array demostration we can see that the address is far away
    from the stack memory address.
    << OUTPUT
    0x123f04080 value: 0 bytes: 4
    0x123f04084 value: 0 bytes: 4
    0x123f04088 value: 0 bytes: 4
    0x123f0408c value: 0 bytes: 4
    0x123f04090 value: 0 bytes: 4
    */

    delete [] heapArray; //Deallocation of the array that was on the heap memory

    return 0;
}