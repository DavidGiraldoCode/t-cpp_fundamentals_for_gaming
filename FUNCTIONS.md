# Functions in C++

## Overview

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

```cpp
SpaceShip::~SpaceShip()
{
	//Clean-up code
}
```

### Functions Const correctness

For every function that is not mutating a class, should be marked as a const. In this way, if I have an instance of the class that is a constant variable, I will be able to use the functions that do not modify the class.
The `conts` at the end of the function means that is wont modify any data of the class
```C++
void print() const
```