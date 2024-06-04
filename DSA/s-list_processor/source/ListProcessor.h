#pragma once
class ListProcessor
{
public:
    ListProcessor();
    void sayHi();
    int * arraySequence(int from, int to);
    int * shuffled(int numbers[]);
    int sumIterative(int numbers[]);
    int sumRecursive(int numbers[]);
};