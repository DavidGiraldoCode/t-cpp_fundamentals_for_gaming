#include <iostream>
#include "ListProcessor.cpp"

ListProcessor listProcessor = ListProcessor();

int main(int argc, char *agrv[])
{
    int from = 9;
    int to = 7;
    try
    {
        int *newSequence = listProcessor.arraySequence(from, to);
        for (size_t i = 0; i < (to - from); i++)
        {
            std::cout << newSequence[i] << "\n";
        }
        delete[] newSequence; // Deallocating heap memory
    }
    catch(std::exception& ex)
    {
        std::cout << "The sequence could not be created: " << ex.what() << "\n";
    }

    return 0;
}