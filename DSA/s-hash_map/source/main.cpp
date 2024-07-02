// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "HashSet.h"

int main(int argc, char *argv[])
{
    HashSet<int> hashSet = HashSet<int>(10);
    return 0;
}

/*
// 
    size_t INITIAL_SIZE = 5;
    int *arrayList = new int[INITIAL_SIZE];
    int array[5] = {0,0,0,0,0};

    std::cout << "Stack Array \n";
    for (size_t i = 0; i < INITIAL_SIZE; i++)
    {
        //arrayList[i] = (int)i;
        std::cout << array[i] << "\n";
    }

    std::cout << "Heap Array \n";
    for (size_t i = 0; i < INITIAL_SIZE; i++)
    {
        arrayList[i] = (int)i;
        std::cout << arrayList[i] << "\n";
    }

    arrayList[INITIAL_SIZE] = 9;
    std::cout << "\n" << arrayList[INITIAL_SIZE] << " new element \n";
    INITIAL_SIZE++;
     for (size_t i = 0; i < INITIAL_SIZE; i++)
    {
        std::cout << arrayList[i] << "\n";
    }
    

    delete[] arrayList;
*/