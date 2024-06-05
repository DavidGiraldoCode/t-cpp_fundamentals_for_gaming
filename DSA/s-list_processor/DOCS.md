# List Processor Docs

## Exercise 1's Populating Lists, takeaways: 

- To return a raw array from a function, we need to use the heap memory. Because raw arrays allocated in the stack memory will be erased once the function ends, returning an invalid reference.
    ```C++
    int sequenceStack[size] = {}; //Allocated in the stack
    int* sequenceHeap = new int[size]; //Allocated in the heap
    ```
- To use a raw array created inside a function, we need to return a pointer to a raw array allocated in the heap memory.
    ```C++
    int * arraySequence(int from, int to)
    {
        int* sequence_address = new int[size];
        return sequence_address;
    }
    ```
- 🚩 Is very important that once we use the dynamically-allocated raw array, we de-allocat that heap memory manually with `delete[] newSequence;`, and thus avoiding memory leaks.
- The return pointer of the raw array only carries the address of the first position of the array in the heap memory. But no information on the size of the array. So, we need to know the size of the array beforehand to be able to iterate over it.
    ```C++
    for (size_t i = 0; i < (to - from); i++)
    {
        listProcessor.arraySequence(from, to)[i];
    }
    ```
- The `range-for-statement` (`for (auto x : arraySequence)`) does not work with the raw array's pointer because it needs a range with a start and end. The pointer does not have that information.
- The  `sizeof()` method will not work either because `sizeof(newSequence)` will return the size in bytes of a pointer and not that of the array.
- Exceptions can be handle with the standar exception classes `<stdexcept>`, in this case with the `logic_error` class, that offers a `what()` method to show the message of the exception.