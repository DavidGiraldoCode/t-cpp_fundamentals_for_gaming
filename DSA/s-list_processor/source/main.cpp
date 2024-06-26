// g++ -std=c++20 main.cpp -o myProgram && ./myProgram
#include <iostream>
#include "ListProcessor.cpp"

ListProcessor listProcessor = ListProcessor();

int main(int argc, char *agrv[])
{
    int from = 2;
    int to = 6;
    try // Wrap the listProcessor calls to catch any exception thrown.
    {
        int *newSequence = listProcessor.arraySequence(from, to);
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
        std::cout << "The Iterative Sum of the Raw Array is: " << listProcessor.sumIterative(newSequence, (to - from)) << "\n";
        std::cout << "The Recursively Sum of the Raw Array is: " << listProcessor.sumRecursive(newSequence, (to - from)) << "\n";
        // for (size_t i = 0; i < (to - from); i++)
        // {
        //     std::cout << newSequence[i] << "\n";
        // }

        delete[] newSequence; // Deallocating heap memory
        delete[] shuffledSequence;
        //========================================================================== Vectors
        std::cout << "\n"
                  << "Vector: " << "\n";

        std::vector<int> newVector = listProcessor.vetorSequence(from, to);
        for (auto num : newVector)
        {
            std::cout << num << "\n";
        }
        std::cout << "Shuffle the list on a Vector: " << "\n";
        std::vector<int> shuffledVector = listProcessor.shuffled(newVector);
        for (auto num : shuffledVector)
        {
            std::cout << num << "\n";
        }
        std::cout << "The Iterative Sum of the Vector Array is: " << listProcessor.sumIterative(newVector) << "\n";
        std::cout << "The Recursive Sum of the Vector Array is: " << listProcessor.sumRecursive(newVector) << "\n";
        
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