// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "ListCreator.h"
#include "Reverse.h"

ListCreator listCreator = ListCreator();
Reverse reversor = Reverse();

int main(int argc, char *argv[])
{
    std::cout << "\nRAW ARRAY ======= \n";
    const size_t NUM_ITEMS = 3;
    int *rawList = new int[NUM_ITEMS];
    rawList = listCreator.arraySequence(0, NUM_ITEMS);
    for(size_t i = 0; i < NUM_ITEMS; i ++)
    {
        std::cout << " rawList[" << i << "]: " << rawList[i] << "\n";
    }
    //TODO explain the differences between method(int *array[]) and method(int *array)

    

    int *reversedRawList = new int[NUM_ITEMS];
    reversedRawList = reversor.reversed(rawList, NUM_ITEMS);

    for(size_t i = 0; i < NUM_ITEMS; i ++)
    {
        std::cout << " reversedRawList[" << i << "]: " << reversedRawList[i] << "\n";
    }
    std::cout << "\nVECTOR ======= \n";

    std::vector<int> vectorList = listCreator.vetorSequence(0, NUM_ITEMS);
    for (auto &&i : vectorList)
    {
        std::cout<< "vectorList: "<< i << "\n"; 
    }
    
    std::vector<int> reversedVectorList = reversor.reversed(vectorList);
    for (auto &&i : reversedVectorList)
    {
        std::cout<< "reversedVectorList: "<< i << "\n"; 
    }

    return 0;
}