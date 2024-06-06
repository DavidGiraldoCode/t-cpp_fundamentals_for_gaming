#pragma once
#include <iostream>
#include <stdexcept>
#include <random>
#include <chrono>
class ListProcessor
{
public:
    ListProcessor();
    void sayHi();
    int *arraySequence(const int from, const int to);
    std::vector<int> vetorSequence(const int from, const int to);
    int *shuffled(const int numbers[], int numbers_size);
    std::vector<int> shuffled(const std::vector<int> &numbers);
    int sumIterative(const int numbers[], const int numbers_size);
    int sumIterative(const std::vector<int> &numbers);
    int sumRecursive(const int numbers[], const int numbers_size);
};