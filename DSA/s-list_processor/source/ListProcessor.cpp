#include <iostream>
#include "ListProcessor.h"

ListProcessor::ListProcessor()
{
    sayHi();
}

void ListProcessor::sayHi()
{
    std::cout << "ListProcessor ready" << "\n";
}
// TODO Exercise 1: Populating Lists
int *ListProcessor::arraySequence(int from, int to)
{
    int newArray[0];
    //! warning: address of stack memory associated with local variable 'newArray' returned
    return newArray; 
}

// TODO Exercise 2: Shuffling Lists
int *ListProcessor::shuffled(int numbers[])
{
    int newArray[0];
    return newArray;
}

// TODO Exercise 3: Summing Lists Iteratively
int ListProcessor::sumIterative(int numbers[])
{
}
// TODO Exercise 4: Summing Lists Recursively
int ListProcessor::sumRecursive(int numbers[])
{
}