# C++ for Gaming

The following my personal notes in C++ fundamentals for game programming and computer graphics. It does not intent to be a formal guidance for third-parties, use it under your responsibility.

## Description

C++ is a general purpose, mid-level programming language, very popular for video game and computer graphics development.

Like Java, it supports Object-Oriented Programming. It is a compiled language, which means that the compiler takes source c++ code and creates binary code. The same source code will compile in several OS*,  and is highly customisable, so it might happen that similar written code might have different behaviour between developers. 

Notice that is easy to write unsafe C++ code; naively C++ is slower than naive Java, because C++ allows the developer to manages it’s own memory. Also, `0` could be many things: pointer, bool, an int. Hence, it is crucial to be aware how the variables and the memory if use along the program.

**Pre-processor directives**

Allows devs to include C++ libraries.

```cpp
#include <iostream>
#include <std>
```

All C++ program has a `main`  function that starts the application. The program returns zero if it runs until completion.

```cpp
int main (int argc, char * argv[])
{
	sdt::cout << "Hello, world! \n";
	return 0;
}
```

**C++ Standard Library `#include <std>`**

Collection of code (clases and functions) available for devs to use. Offers useful functionally like Strings, IO, files, vectors, set, map, and algorithms like sorting and others. One need to reference the library with the namespace `std::` . The namespace encapsules code, like `std::string` or `std::vector`

## **File name convention**

```bash
./program_folder
	|─ main.cpp
	└─ main.h
```

Classes are separated into two files:

- Headers files .h: Use for function and class **declarations**.
    - **Separating design form implementation** 💙: Allows developers quickly see all functionality of a class without going through the entire definition. One need to declare function name, return type, arguments type.
        
        ```cpp
        class SpaceShip
        {
        	public:
        	
        	float posX;
        	float posY;
        	
        	void shot();
        	void destroy();
        	// and much more without getting into the details
        }
        ```
        
        In the compilation process, if the header file changes, all the sources files using that class will re-compile. But if the source file changes, it does not affect it dependencies.
        
        ⚠️ Problematic with cyclic dependencies error.
        
- Source files .ccp: Use for function and class **definitions (implementations).**
    - C++ requiere to see all clases, functions and variables before using them. So it will use the directive on top on the file to bring the code of the required class.
    
    ```cpp
    // This indicates the compiler that all the definitions
    #include "SpaceShip.h" 
    // for the SpaceShip can be found in SpaceShip.h
    
    void myFunction()
    {
    	SpaceShip mySpaceShip;
    	mySpaceShip.shot();
    	
    	doSomething(); // ERROR This function is being called without being declare first
    
    }
    
    void doSomething()
    {
    	//Definitions
    }
    ```
    

## **Compilation process**

C++ does not have virtual machine (like JAVA), needs to compile the code before running it (unlike Javascript). The compilation achives faster execution.

```bash
1. Pre-processos runs -> Source(.cpp) and header(.h) files
|		|─ Looks at directives to include (copies and paste) 
|		|		libraries, files, macros, onto the source file.
|		└─ Stops if pre-processor error occurs	
|
2. << Pre-processor OUTPUT
3. Compiler runs the Pre-processor's output
|		└─ Automatically produces a.out for smaller programs
|		└─ Stops if compilation error occurs	
|
4. << OUTPUT: Object files(.o)
5. Linker: Links objects(.o) files together
|	  └─ Stops if compilation error occurs	
|
6. << OUTPUT: binary executable //Runs by the CPU
```

Use `g++ main.cpp` to compile. The flag `-o` specifies the name of the .out file.

```bash
g++ -std=c++20 main.cpp -o HelloWorld

g++ *.cpp -o myProgram #Will re-compile ALL

#One can separete the compilation process by steps

g++ -E myProgram.cpp > myProgram.s #Creates the compiler file after the pre-processing
g++ -c myProgram.cpp #Compiles to an object .o file
g++ -o myProgram main.o #Links all the objec files together
```

One can re-compile only specific files that have changed. Linking is faster than compiling. This process can be automated using CMake.

**Troubleshooting,** When errors occur, read the top of the error stack.

## Primitive types

| Type | Bytes | Range |
| --- | --- | --- |
| char | 1 |  |
| short | 2 |  |
| long | 4 |  |
| int | *(4) | -/+ 32,768 |
| float | 4 | 7 digits |
| double | 8 | 15 digits |
| long double | 10 | 19 digits |
| bool | 1 | 0,1 |

pre-increment/decrement `++a` `--a`

post-increment/decrement `a++` `a--`

AND `a & b`

OR `a | b`

NOT `~a`

## **Functions in C++**

```cpp
//returnType functionName (args) { definition; }

void doSomething( int x, char c)
{
	x++;
}

void doSomething( float posX, float posY) // THIS WORKS
{
	// Another implementation
}

//Cannot use same function name with different return type
bool doSomething() // This DOES NOT WORK
{
	return false;
}

bool isAlive(){
	return true;
}
```

## Classes in C++

`m_` at the begging of a variable is a convention to indicate that a given variable is a private member of the current class. Makes stop the private variables quickly.

```cpp
class SpaceShip
{
	int m_posX = 0; //Private visibility by default
	int m_posY = 0;
public: //Everything
	SpaceShip(int x, int y);
	int getPosX();
	int getPosY();
}
```

Class constructor

```cpp
SpaceShip::SpaceShip(int x, int y)
{
	m_posX = x;
	m_posY = y;
}

// Member initializer lists gives this variables the initial value
SpaceShip::SpaceShip(int x, int y)
	: m_posX(x)
	, m_posY(y)
{
	// Construction definition
}
```

Class destructor (when my object gets our of scope)

```cpp
SpaceShip::~SpaceShip()
{
	//Clean-up code
}
```

## STL Containers

```cpp
std::vector<T> 
// T is the Type of the object to be contained.
// Objects cotained here REQUIRE a default constructor.

std::set<T>
// Its an ordered set of Objects 
// T REQUIERE a < operator for the set to compare between instances
// Only store unique values

std::map<T1, T2>
// Map one type to another
```

Usage of `std::vector<T>` 

```cpp
std::vector<int> vec;
std::vector<int> vec(num, value); // size, values
vec.push_back(value); // add to back
vec.pop(); // remove from back
vec.clear(); // clear all
vec.reserve(n); // set capacity
vec[i] = value; // access
```

## References

Dave Churchill (2023) COMP4300 - Game Programming - Lecture 02 - Intro to C++ (1/2) [https://youtu.be/rq0oMlWZhdI](https://youtu.be/rq0oMlWZhdI?si=t-GczFoCOnaNhDQB)