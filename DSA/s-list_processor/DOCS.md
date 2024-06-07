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
- The `sizeof()` method will not work either because `sizeof(newSequence)` will return the size in bytes of a pointer and not that of the array.
- Exceptions can be handle with the standar exception classes `<stdexcept>`, in this case with the `logic_error` class, that offers a `what()` method to show the message of the exception.

## Exercise 2's Shuffling Lists, takeaways:

- The `int *ListProcessor::shuffled(int numbers[], int numbers_size = 0)` method needed the `numbers_size` argument to know the size of the raw array explicitly.
- The create random numbers in C++ we can use the `std::mt19937_64`, which creates an engine that given a seed (starting point of a sequence of pseudorandom numbers) can generate a random number. To control the range in which the random number in generated we use `std::uniform_int_distribution<T>` function object.

```C++
    unsigned seed = 3353;
    std::mt19937_64 random_engine(seed);
    std::uniform_int_distribution<int> int_dis{0, 5};
    int random = int_dis(random_engine);
```

- One seed can only generate one random number, we need to change the seed somehow. Measuring the time during runtime is a good option. The `std::chrono` class offers ways to do that.

```C++
    auto t1 = std::chrono::high_resolution_clock::now(); // To get the time at this moment
    std::chrono::duration timelapse = t1 - t2; // To get the timelapse between to time points.
    timelapse.count(); // To count how much time has passed.
```

## Exercise 3's Summing Lists Iteratively, takeaways:

- Passing the pointer of the raw dynamically allocated array as an argument, exposes the array to be mutated by the function

```C++
void doSomeThing(int numbers[])
{
    numbers[0] = 69; //Arbitrarly changing a value inside the array
}

int *newSequence = listProcessor.arraySequence(1, 5);
listProcessor.sumIterative(newSequence);
//Now newSequence has a 69 in its first possition istead of a 1
```

- To protect the array from being mutated, we can use `conts` infront of the argument. So `numbers` is now being passed as a constant reference

```C++
int ListProcessor::sumIterative(const std::vector<int> &numbers)
```

## Exercise 4's Summing Lists Recursively, takeaways:

- When using recurssion on a method with a return type different from void, we need to calle the recurssion on the return. Otherwize we are not passing any values.

```C++
int ListProcessor::sumRecursive(const int numbers[], const int numbers_size = 0)
{
    // Base cases
    // Recursive cases
    return sumRecursive(shrinkingArray, size);
}
```

- **🧠 REMEMBER!:** In C++, int my_array[n] or int * my_array = new my_array[n] are addresses, pointing to the first position of the element inside the array. Since all the elements inside the array are linearly allocated, we only need to address the first one. This leads to important considerations and risks:
> Pointer Arithmetic: I can potentially add an int to the pointer of the array, such as `my_array + 1`, and thus change the position it now points to. Now, the pointer `my_array` will be pointing to `my_array[1]`.
> However, if we keep adding, the pointer could eventually exceed the bounds of the array, accessing memory that is not allowed to modify. This highlights the importance of being cautious when using raw array's pointer.
Heres an example of the recursive solution but with pointers (ChatGPT 2024):

```C++
int ListProcessor::sumRecursive(const int numbers[], int numbers_size) {
    // Base cases
    if (numbers_size == 0) {
        return 0;
    }
    if (numbers_size == 1) {
        return numbers[0];
    }

    // Recursive case
    // Note: numbers + 1 is safe as long as numbers_size > 1
    return numbers[0] + sumRecursive(numbers + 1, numbers_size - 1);
}
```

