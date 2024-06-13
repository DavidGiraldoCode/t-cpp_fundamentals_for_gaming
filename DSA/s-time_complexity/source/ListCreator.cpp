#include "ListCreator.h"

ListCreator::ListCreator()
{
    std::cout << "ListCreator ready" << "\n";
}
ListCreator::~ListCreator()
{
    std::cout << "ListCreator destroyed" << "\n";
}

int *ListCreator::arraySequence(const int from, const int to)
{
    if (from == to)
        return new int[0]; // empty array
    if (from > to)
        throw std::logic_error{"The beginning of the sequence should be grater than the end"}; // IllegalArgumentException

    int size = to - from;
    int *sequence = new int[size]; // Recall, this is allocated in heap memory, the caller has to delete it after use.

    for (size_t i = 0; i < size; i++)
    {
        sequence[i] = from + i;
        // std::cout << sequence[i] << "\n";
    }
    return sequence;
}

std::vector<int> ListCreator::vetorSequence(const int from, const int to)
{
    if (from == to)
        return {}; // empty array
    if (from > to)
        throw std::logic_error{"The beginning of the sequence should be grater than the end"}; // IllegalArgumentException

    int size = to - from;
    std::vector<int> sequence(size); // Recall, this is allocated in heap memory, the caller has to delete it after use.

    for (size_t i = 0; i < sequence.size(); i++)
    {
        sequence[i] = from + i;
        // std::cout << sequence[i] << "\n";
    }
    return sequence; //? Does it get pass as value or reference?
}