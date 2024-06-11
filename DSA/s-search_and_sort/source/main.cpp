// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "EnemyShip.h"
#include "EnemyProcessor.h"

//TODO use Resource Acquisition is Initialization (RAII) pattern 

int main(int argc, char * argv[])
{
    EnemyShip enemyOne = EnemyShip(4, 6, 10);
    EnemyShip enemyTwo = EnemyShip(3, 2, 5);
    std::cout << enemyOne.volume() << "\n";
    std::cout << enemyTwo.volume() << "\n";
    std::cout << "enemyOne is: " << enemyOne.compareTo(enemyTwo) << " than enemyTwo \n";
    return 0;
}