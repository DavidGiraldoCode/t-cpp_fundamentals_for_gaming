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
    int tip = 0;
    int end = arraySize - 1;
    while(tip < arraySize-1/2)
    {
        int tempCopy = array[tip];
        reversedArray[tip] = array[end];
        reversedArray[end] = tempCopy;
        tip ++;
        end --;
    }
    return reversedArray;
}

std::vector<int> Reverse::reversed(const std::vector<int> &list)
{
    std::vector<int> reversedList(list.size());
    int tip = 0;
    int end = list.size()-1;
    while (tip < list.size()-1 / 2)
    {
       //int tempCopy = list[tip];
       reversedList[tip] = list[end];
       reversedList[end] = list[tip];
       tip ++;
       end --;
    }
    
    return reversedList;
}