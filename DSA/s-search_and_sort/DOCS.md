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
- The method `virtual int compareTo(T &another) = 0;` is an example of a pure-vitual method.

#### Interfaces in C++
- They are abstract classes that can not be instantiable.
- Provide only virtual method that described desirable behavior.
- It does not have data memebers.
- It provides a virtual destructor. 