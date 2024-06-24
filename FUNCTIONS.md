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

For every function that is not mutating a class, should be marked as a const. In this way, if one has an instance of the class that is a constant variable, it will be able to use the functions that do not modify the class.
The `conts` at the end of the function means that it implementation wont modify any data of the class. In other words this define **read-only** methods.
```C++
void print() const
```

When I want to return a reference and make sure that reference cannot be mutate, the return type of that member function must be `const`

```C++
class Container {
private:
    int elements[10];
public:
    const int* getElements() const {
        return elements;
    }
};

int main() {
    Container c;
    const int* elems = c.getElements();
    // elems[0] = 10; // Error: cannot modify const int
    return 0;
}
```