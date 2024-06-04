#include <iostream>
#include "ListProcessor.cpp"

ListProcessor listProcessor = ListProcessor();

int main (int argc, char* agrv[])
{
    std::cout << "Hello List Processor!" << "\n";
    listProcessor.sayHi();
    return 0;
}