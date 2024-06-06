#include "ListProcessor.h"

ListProcessor::ListProcessor()
{
    sayHi();
}

void ListProcessor::sayHi()
{
    std::cout << "ListProcessor ready" << "\n";
}
// TODO Exercise 1: Populating Lists
int *ListProcessor::arraySequence(int from, int to)
{
    if (from == to)
        return new int[0]; // empty array
    if (from > to)
        throw std::logic_error{"The beginning of the sequence should be grater than the end"}; // IllegalArgumentException

    int size = to - from;
    int *sequence = new int[size]; // Recall, this is allocated in heap memory, the caller has to delete it after use.

    for (size_t i = 0; i < size; i++)
    {
        sequence[i] = from + i;
        // std::cout << sequence[i] << "\n";
    }
    return sequence;
}

std::vector<int> ListProcessor::vetorSequence(int from, int to)
{
    if (from == to)
        return {}; // empty array
    if (from > to)
        throw std::logic_error{"The beginning of the sequence should be grater than the end"}; // IllegalArgumentException

    int size = to - from;
    std::vector<int> sequence(size); // Recall, this is allocated in heap memory, the caller has to delete it after use.

    for (size_t i = 0; i < sequence.size(); i++)
    {
        sequence[i] = from + i;
        // std::cout << sequence[i] << "\n";
    }
    return sequence; //? Does it get pass as value or reference?
}

// TODO Exercise 2: Shuffling Lists
int *ListProcessor::shuffled(int numbers[], int numbers_size = 0)
{
    int size = numbers_size;
    int index = 0;
    int *shuffledArray = new int[size];

    auto t0 = std::chrono::high_resolution_clock::now();
    auto t1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration timelapse = t1 - t0;
    unsigned seed = timelapse.count();

    std::unordered_map<int, int> randomRecords{};

    while (index < numbers_size)
    {
        std::mt19937_64 mt_engine{seed};
        std::uniform_int_distribution<int> int_d{0, size - 1};
        int randNum = int_d(mt_engine);
        if (randomRecords.count(randNum) == 0)
        {
            randomRecords[randNum] = index;
            shuffledArray[index] = numbers[randNum];
            t1 = std::chrono::high_resolution_clock::now();
            timelapse = t1 - t0;
            seed = timelapse.count();
            index++;
        }
        else
        {
            t1 = std::chrono::high_resolution_clock::now();
            timelapse = t1 - t0;
            seed = timelapse.count();
        }
    }

    return shuffledArray;
}

// TODO Exercise 3: Summing Lists Iteratively
int ListProcessor::sumIterative(int numbers[])
{
    return 0;
}
// TODO Exercise 4: Summing Lists Recursively
int ListProcessor::sumRecursive(int numbers[])
{
    return 0;
}