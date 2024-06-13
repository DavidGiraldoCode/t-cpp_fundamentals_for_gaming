#pragma once
#include <iostream>
#include <vector>

class Reverse
{
public:
    Reverse();
    //? Do all classes need destructor even when they do not have dynamically allocated data?
    ~Reverse();
    /**
     * Return a reversed copy of the argument Array/List.
     * The passed List is NOT mutated.
     *
     * @param list A List.
     * @return A reversed copy of list.
     */
    int* reversed(const int* array, const size_t arraySize);
    std::vector<int> reversed(const std::vector<int> &list);
};