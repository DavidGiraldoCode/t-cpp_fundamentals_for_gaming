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
int * ListProcessor::arraySequence(int from, int to)
{
    if(from == to) return new int[0]; //empty array
    if(from > to) throw std::logic_error{"The beginning of the sequence should be grater than the end"}; //IllegalArgumentException

    int size = to - from;
    int* sequence = new int[size]; //Recall, this is allocated in heap memory, the caller has to delete it after use.

    for(size_t i = 0; i < size; i ++)
    {
        sequence[i] = from + i;
        //std::cout << sequence[i] << "\n";
    }
    return sequence; 
}

// TODO Exercise 2: Shuffling Lists
int *ListProcessor::shuffled(int numbers[])
{
    int* sequence = new int[0];
    return sequence;
}

// TODO Exercise 3: Summing Lists Iteratively
int ListProcessor::sumIterative(int numbers[])
{
    return 0;
}
// TODO Exercise 4: Summing Lists Recursively
int ListProcessor::sumRecursive(int numbers[])
{
    return 0;
}