# Stack - Abstract Data Type

The Stack Bastract Data Type has the icon basic behavior: _LIFO_ (Last In First Out) ![push and pop](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

## Implemanting Stack as an Interface of Linked List

* `void push(T elem)` Adds the element to the top of the stack.

* `T pop()` Removes and returns the top element in the stack, that is the element that was last added to the stack. **Throws an EmptyStackException if the stack is empty!**

* `T top()` Returns the top element in the stack without removing it. **Throws an EmptyStackException if the stack is empty!**

* `int size()` Returns the number of elements in the stack.

* `boolean isEmpty()` Returns true if the stack is empty.

## Declaration of Interfaces in C++

In C++ there is not such thing as `Interface` key word as in Java. But there are ways to represent the same behaviour using C++ pure-virtual classes and methods without any definition. To do so, here are some basic things to consider:

- `virtual` classes create a contract with the derived classes. Whoever inherit this classes must implement all the methods. This methods _define behaviours_ on a header file.
- `virtual` classes are treated as abstract classes that can not be instantiable, thus, they **DO NOT** have a constructor.
- They **DO HAVE** a virtual `~Destructor`.
- They do not have member variables.
- To **REQUIRE** the impementation of a `virtual` method we use the sufix `= 0;` at the end of the method. This are called a pure-virtual method.

```C++
//.h file
#pragma once
class Interface{
// NO members
public:
    //NO constructor
    virtual ~Interface() = default;
    virtual void pop() = 0;
    virtual int compareTo(T &another) = 0;
}
```

## Implementing interfaces in C++

As mentioned before, Interfaces are pure-virtual clases unabled to intiatiate objects, so derived clases must implement their metods. Heres is how:

- The derived class must import the interface, and the `:` defines an inheritance relationship between a derived class and a base class.
- The `override` key word indicated which methods are inherit from the interface an are being implemented.
- Using `virtual` before the method is allow, but redundant.

```C++
#include "Interface.h"
class DerivedClass : public Interface{
public:
    DerivedClass();
    ~DerivedClass();
    virtual void pop() override;
    int compareTo(T &another) override;
}
```

## Errors

Abstract classes, in this case an Interface cannot instantiate any objects, it will yield an error: 
```bash
main.cpp:7:23: error: allocating an object of abstract class type 'LinkedList<int>'
    Stack<int> list = LinkedList<int>();
```

To be able to use a more clear way of declaring a Stack, one can use aliases:

```C++
// Define a type alias
template <typename T>
using StackList = LinkedList<T>;
StackList<int> stack = LinkedList<int>();
```

## Future work

- [ ] Implemented the Stack using arrays, and dynamic re-sizing