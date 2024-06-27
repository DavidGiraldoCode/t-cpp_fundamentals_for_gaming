# Notes

This time, we are adding the header file `EnemyShip.h` at the top of the main.ccp. Therefore, we need to include on the compiler instruction all the .cpp files, so the line to execute this program is `g++ -std=c++20 *.cpp -o myProgram && ./myProgram`. Notice how `*.cpp` includes all the files and not only `mian.cpp`. If it just included `mian.cpp`, it would have yielded a linker error.

```bash
g++ -std=c++20 main.cpp -o myProgram && ./myProgram
Undefined symbols for architecture arm64:
  "EnemyShip::volume()", referenced from:
      _main in main-93eea1.o
  "EnemyShip::EnemyShip(int, int, int)", referenced from:
      _main in main-93eea1.o
ld: symbol(s) not found for architecture arm64
clang: error: linker command failed with exit code 1 (use -v to see invocation)
```

### Exercise 1: Comparable Box - Takeaways
- In C++ the Object-Oriented concept of Interface does not exist as a feature of the language itself. In Java, there is a reserved word for `Interface`. Therefore, to create Interfaces, we need to follow the principles ourselves by using C++ pure-virtual classes and methods without any definition. [Deciphering Object-Oriented Programming with C++, Chapter 8](https://learning.oreilly.com/library/view/deciphering-object-oriented-programming/9781804613900/B19087_08.xhtml#_idParaDest-164). C++ Crash course, Chapter 5.
- The `:` defines an inheritance relationship between a derived class and a base class.
- Defining methods as `virtual` means that a derived class will implement them, and the base class holding this method can not initantiate any objects.
- To require the impementation of a `virtual` method, we use the sufix `= 0;` at the end of the method.
- The method `virtual int compareTo(T &another) = 0;` is an example of a pure-virtual method.

#### Interfaces in C++
- They are abstract classes that can not be instantiable.
- Provide only virtual method that described desirable behavior.
- It does not have data memebers.
- It provides a virtual destructor. 


### Exercise 2: Sorting - Takeaways
- I implemented an abstract base class to process the enemies. The derived classes implement different sorting algorithms.
- Linear pedendencies could happen when using containers that refere to classes they contain. Always use `#pragma once` to avoid this type of conflicts.
- With raw arrays, one can create array of user-defined objects and instantiate them in different ways
```C++
EnemyShip* enemyRAWFleetA = new EnemyShip[FLEET_SIZE]{{4, 6, 10},{4, 6, 10}};

EnemyShip* enemyRAWFleetB = new EnemyShip[FLEET_SIZE];
enemyRAWFleetB[0] = new EnemyShip(4, 6, 10);
```
- Recall that the `new` keyword create a pointer to dynamically allocated heap memory. After using the resources in the RAW array, always deallocate it with `delete [] NameOfTheArray;`
- Object without default / copy constructors will yield an error if you try to store them into a `std::vector`. The standar `vector<T>` container needs a copy constructor that takes a costant reference to another object like so: 
```C++
EnemyShip::EnemyShip(const EnemyShip &other) : m_height(other.getHeight()){}
//Moreover, the functions to retunr the memeber should be const
int getHeight() const {...}
```

### Exercise 3: Sequential Search - Takeaways
- Brute force approach, fairly simply and straightforward.
- I declare and defined the two overloaded methods on the base class, and either of the derived classes can use it.

### Exercise 4: Binary Search
- For the divide and conquer strategy, I defined three utility varaibles, `cursor` as index to move around, `min` and `max` as the dynamic ranges.
- The `while` loop must consider a range of size 1 to cover cases in which the elements are on the extrem edges, like so:
```C++
target = 12;
array[0] = 12;

while ((max - min) >= 0) {...}// This loop will stop when the range is 1 -> 1 - 0
while ((max - min) > 0) {...}// This loop will stop when the range is 2 -> 2 - 1
```
- The `cursor` should be offseted by the min range like so `cursor = min + (int)((max - min) / 2);`