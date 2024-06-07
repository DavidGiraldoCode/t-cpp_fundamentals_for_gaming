// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "EnemyShip.h"

//TODO use Resource Acquisition is Initialization (RAII) pattern 

int main(int argc, char * argv[])
{
    EnemyShip enemy = EnemyShip(4, 6, 10);
    std::cout << enemy.volume() << "\n";
    return 0;
}