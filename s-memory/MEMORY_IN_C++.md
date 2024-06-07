# Memory in C++
## Overview

C++ allows developers to get access to some location in RAM during the compilation process and RunTime. There are two types of memory we can manipulate: **stack memory** and **heap memory.** Both types store the data in the computer, and we can request it and change it, but there are some characteristics that we need to consider because they differ in size, allocation, speed and syntax.

## Stack vs Heap memory

|  Type | What stores? | Size & Data structure | Usage |
| --- | --- | --- | --- |
| Stack | Everything related to the program execution at compile time: OS specifics, Primitives, Functions calls, Pointers (NOT necessarily  data at the pointer). | Static memory (megabytes), and when it rans out, yields: Stack overflow. It is fast, but limited. Has a “first in, last out” structure. It is stored altogether linearly in memory. And gets deallocated automatically. | To allocate fixed-sized memory for local variables that are known at compile time. Local variables without the new keyword get allocated by default in the stack memory. |
| Heap | Anything that the developer determines both at compile time and runtime. The actual data at a given pointer. | Dynamic memory (available RAM). Its is slow, but larger, complicated & expensive. It is stored in a randomly available  space. It could be far away from the stack memory addresses. Does not get deallocated, needs to be deleted manually. | To allocate dynamic-sized memory (during compile and runtime), useful for larger or variable-sized data. * & new indicates that is using pointers, then the size int ,float, MyClass of the memory to allocate. The memory is accessed via pointers. Once we finished using the data, we use delete to free the space in RAM. |

```cpp
int level = 1; // stack memory
int* metaLevel = new int // heap memory

*metaLevel = 1 // de-refence to set a value
```

## What is a Pointer?

It is a **memory address**, an unsigned **integer** (no -/+ sign) that stores a memory address in RAM on the computer. To modify a pointer is to modify the address, not the actual interesting data value. To modify the value we dereference the pointer using the `*` operator.

We can use the **stack memory** with pointers with `*` and `&` operators

```cpp
int i = 6; // 4 bytes is allocated on the stack memory
int * p; // creater a pointer to an int, the p is 4 bytes big
p = &i; // & = address of
*p = 7; // * = dereference, or value at address
```

***⚠️ UnInitialised values in C++ are unsafe,** because the stack will assigned to that variable whatever is on RAM at that time (garbage values) and relys on future code to set them.

Always prefer variables explicit initialization over assignment  to avoid undefined behavior.

### Proper usage of pointers

```cpp
int* ptr = new int; // Allocation
*ptr = 10; // Dereference to set value
delete ptr; // Deallocation
```

The `new` keyword allocates (heap) memory dynamically, by telling the system to look for **available continuous memory (row)** where it can save data, and returns the pointer to that space in memory. The `*`  works as an “at” that reads: “The data that is ***at*** this location, assign this value”. On the other hand, `delete`  deallocates dynamic memory, preventing leaks.

Both `new` and `delete`  are expensive because ran multiple operation under the hood to allocate and deallocate continuous available space in RAM, (it might need to re-allocate other things).

## What are Memory Leaks?

Memory leaks is a consequence of not deallocating dynamically allocated memory. Over time, the program will runs out of RAM until it crashes.  For instance, managing heap memory manually with **`new`** and **`delete`** increases the risk of memory leaks.

## When and Why use pointers?

1. **OOP inheritance:**  Parents and children may be of different size, and remember that is we use the stack memory, we need predetermine and known size at compile time.
    1. Recall, In object-oriented programming (OOP), inheritance allows one class (the child class) to inherit properties and behaviours from another class (the parent class). When you use inheritance, you can create a hierarchy of classes where child classes inherit attributes and methods from parent classes. Polymorphism allows objects of different classes to be treated as objects of a common superclass.
    
    ```cpp
    Parent * pointerParent = new Child(); 
    // Recall that new returns a pointer to the heap memory 
    // where the Child type is allocated
    ```
    
2. **To modify a variable’s value inside a function:** When we pass arguments to a function, a copy of that variable’s value gets passed into the function. NOT the actual variable. So we pass instead the pointer of the data we want to change, and dereference the pointer to modify the value. We use the `&` ”address(in RAM)-of” operator to pass the pointer to the function.
    
    ```cpp
    #include <iostream>
    
    // Function that increments the value of an integer using a pointer
    void increment(int* numPtr) {
        (*numPtr)++; // Dereference the pointer to access and modify the value
    }
    
    int main() {
        int num = 5;
        std::cout << "Before increment: " << num << std::endl;
    
        // Pass the address of num to the increment function
        increment(&num);
    
        std::cout << "After increment: " << num << std::endl;
        return 0;
    }
    ```
    
3. **Manipulate large data:** Larger pieces of data (gigabytes) cannot be on the stack memory. They need to go on the heap memory, so we need pointer to get it.

## What are references `&` in C++?

They are like “safe pointers”, where we use the “address(in RAM)-of” operator `&` . And this is telling the address of EXISTING data, it cannot point to nothing or nullPointer. So it is preferable to use references instead of pointers.

By default, C++ passes variables by value (PBV), and is expensive is the variable holds large amounts of data. 

```cpp
//Tnnify example by Professor Dave Churchill, modified by me

#include <iostream>

void tennifyByPointer(int * a)
{
    if (a != nullptr) {
        *a = 10;
    } else {
        std::cerr << "Error: Null pointer encountered at tennify function\n";
    }
}

void twentifyByReference(int & b)
{
	b = 20;
}

int main()
{
    int i = 12;
    int *ptr_i = &i;
    tennifyByPointer(ptr_i);
    std::cout << i << "\n";
    
    // Test with a null pointer
    int *null_ptr = nullptr;
    tennifyByPointer(null_ptr); // This will print an error message
    
    twentifyByReference(i);
     std::cout << i << "\n";
    
    return 0;
}
```

Notice that **`nullptr`** is a type-safe C++ keyword that represents a null pointer constant (replace `NULL`), which is a special value that can be assigned to a pointer variable to indicate that it does not point to any memory location. Provides a clearer and more expressive way to indicate null pointers.

By passing references we are passing address, and it cheaper for the computer. If we do not want to modify the data, but neither get our original variable duplicated for the sake of saving memory, we **pass a constant reference** like this:

```cpp
void machineLearn(const BigData & d){/* Do something */}

int main()
{
	BigData data();
	machineLearn(data); 
	// we passed the data object for learning, but not to mutate it.
}
```

`const Type & variable` means that the variables cannot be modified inside the function.

### Exceptions to PassByReference

- If the data type is equal or less than the size of a pointer (4 bytes in 32 bits and 8 in 64), then pass the by value `int add(const int a, const int b);`
- Deference has extra steps when is used for primitives, which results in slower programs.
- Pass smart pointers `std::shared_ptr<T>` by value, because the copy of these types has useful information.

### Equivalence between `&` and `*`

```cpp
int a = 1;
int * pa = &a; // to the pointer pa assign the "address-of" a;

//This to lines do exactly the same
*(&a) = 2; //The value living "at" the "address-of" a assign 2
*pa = 2; //The value living "at" the pointer pa assign 2
```

### Array allocation

```cpp
int inventory[10]; // Allocate an array os size 10 on the stack memory
int* collection = new int[10]; // Allocate an array on the heap memory

collection[0] = 2;

delete [] collection; // Deletes the allocated data in the heap memory
```

When creating dynamic array using heap memory, the `new` keyword **returns the address** of *the first element of the array*.

The **size of a raw array is complicated to determine at runtime** because they do not carry the information of their current size. Its need to be determine using `sizeof()` that returns the size of a given variables in bytes.

```cpp
int inventory[10]; // Declares an array of 10 integers, 4 bytes * 10
size_t rawSize = sizeof(inventory); //  4 bytes * 10 = 40 bytes;
size_t positionSize = sizeof(inventory[0]; // 4 bytes

// Calculate the number of elements in the array
size_t inventorySize = rawSize / positionSize;// 40 / 4 = 10;
```

### Class allocation

```cpp
class Alien
{
	int m_level = 0; // stack memory allocation
	int* m_posX = new int; // heap memory allocation
	int* m_posY = new int; // heap memory allocation
public:
	Alien(int level, int posX, int posY)
		: m_level(level)
		, m_posX(posX)
		, m_posY(posY)
	{
		
	}
}

Alien goodAlien(args); // stack memory
Alien * badAlien = new Alien(args); // Allocate the object on heap memory

goodAlien; //--> Will still have some attributes in the heap memory
delete badAlien; // Deletes the allocated data in the heap memory
```