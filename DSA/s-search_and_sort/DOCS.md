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