// g++ -std=c++20 main.cpp -o myProgram && ./myProgram
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
        std::cout << "Shuffle the list on a Raw Array: " << "\n";
        int *shuffledSequence = listProcessor.shuffled(newSequence, (to - from));
        for (size_t i = 0; i < (to - from); i++)
        {
            std::cout << shuffledSequence[i] << "\n";
        }

        delete[] newSequence; // Deallocating heap memory
        std::cout << "Vector: " << "\n";
        for (auto num : newVector)
        {
            // std::cout << num << "\n";
        }
    }
    catch (std::exception &ex)
    {
        std::cout << "The sequence could not be created: " << ex.what() << "\n";
    }

    return 0;
}