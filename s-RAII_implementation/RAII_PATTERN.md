## Resource Acquisition is Initialization (RAII)

RAII is a design pattern in C++ that automates resource management using **object lifetime**, ensuring that dynamically allocated memory gets release once it gets out of scope.

### Implementation

1. Encapsulate each resource into a `class myRAII{}`
2. The constructor  `myRAII(){}` acquires and initializes the resource accordingly using `new`
3. The destructor `~myRAII(){}` releases the resource using `delete`
4. The class must be instantiated: so it has automatic storage duration (or in another RAII object).

```cpp
//RAII example by Professor Dave Churchill

//----------------- IntArray.cpp
class IntArray
{
	int * array; // Creates a pointer
public:

	IntArray(size_t size)// Constructor
	{
		array = new int[size]; //Create a pointer in heap memory
	}
	
	~IntArray()// Destructor ~
	{
		delete [] array; // goes through the array's position deleting the data
	}
	
	int & operator [] (size_t i)
	{ 
		return array[i]; 
	}
}

//----------------- main.cpp
#include "IntArray.h"
int main()
{
	IntArray arr(10); // Heap memory allocated
	arr[5] = 1;
	//At the end of the program, the arr gets destroyed, heap memory deallocated 
}
```