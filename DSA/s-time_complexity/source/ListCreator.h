#pragma once
#include <iostream>
#include <stdexcept>
class ListCreator
{
public:
    ListCreator();
    ~ListCreator();
    int *arraySequence(const int from, const int to);
    std::vector<int> vetorSequence(const int from, const int to);
};