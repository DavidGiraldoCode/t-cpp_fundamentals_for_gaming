// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "ListCreator.h"
#include "Reverse.h"

ListCreator listCreator = ListCreator();
Reverse reversor = Reverse();

int main(int argc, char *argv[])
{
    const size_t NUM_ITEMS = 10;
    int *rawList = new int[NUM_ITEMS];
    rawList = listCreator.arraySequence(0, NUM_ITEMS);
    //TODO explain the differences between method(int *array[]) and method(int *array)

    std::vector<int> vectorList = listCreator.vetorSequence(0, NUM_ITEMS);

    int *reversedRawList = new int[NUM_ITEMS];
    reversedRawList = reversor.reversed(rawList, NUM_ITEMS);

    return 0;
}