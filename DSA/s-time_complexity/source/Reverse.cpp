#include "Reverse.h"

Reverse::Reverse()
{
    std::cout << "Reversor ready \n";
}
Reverse::~Reverse()
{
    std::cout << "Reversor death \n";
}

int *Reverse::reversed(const int *array, const size_t arraySize)
{
    int *reversedArray = new int[arraySize];
    return reversedArray;
}

std::vector<int> Reverse::reversed(const std::vector<int> &list)
{
    std::vector<int> reversedList(list.size());
    return reversedList;
}