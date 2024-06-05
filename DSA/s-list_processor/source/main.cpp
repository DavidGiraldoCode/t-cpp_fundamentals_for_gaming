#include <iostream>
#include "ListProcessor.cpp"

ListProcessor listProcessor = ListProcessor();

int main(int argc, char *agrv[])
{
    int from = 0;
    int to = 7;
    try // Wrap the listProcessor calls to catch any exception thrown.
    {
        int *newSequence = listProcessor.arraySequence(from, to);
        std::vector<int> newVector = listProcessor.vetorSequence(from, to);

        for (size_t i = 0; i < (to - from); i++)
        {
            std::cout << newSequence[i] << "\n";
        }
        delete[] newSequence; // Deallocating heap memory
        std::cout << "Vector: " << "\n";
        for (auto num : newVector)
        {
            std::cout << num << "\n";
        }
    }
    catch (std::exception &ex)
    {
        std::cout << "The sequence could not be created: " << ex.what() << "\n";
    }

    return 0;
}