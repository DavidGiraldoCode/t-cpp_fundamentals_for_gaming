// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "EnemyShip.h"
#include "EnemyProcessor.h"
#include "EnemySelectionProcessor.h"

// TODO use Resource Acquisition is Initialization (RAII) pattern

void sorting()
{
    std::cout << "My RAW Array Fleet \n";
    const size_t FLEET_SIZE = 6;                         // The value that difines the aray most be constant
    EnemyShip *enemyRAWFleet = new EnemyShip[FLEET_SIZE]{//! Dynamically allocated!
                                                         {4, 6, 10},
                                                         {3, 3, 8},
                                                         {4, 8, 12},
                                                         {4, 6, 10},
                                                         {5, 7, 12},
                                                         {2, 3, 5}};

    for (size_t i = 0; i < FLEET_SIZE; i++)
    {
        std::cout << enemyRAWFleet[i].volume() << "\n";
    }

    std::cout << "Selection sort \n";
    EnemySelectionProcessor eSelectionProcessor = EnemySelectionProcessor();
    eSelectionProcessor.sort(enemyRAWFleet, FLEET_SIZE);
    for (size_t i = 0; i < FLEET_SIZE; i++)
    {
        std::cout << enemyRAWFleet[i].volume() << "\n";
    }

    delete[] enemyRAWFleet; //* De-allocation of heap memory

    std::cout << "My Vector Fleet \n";
    std::vector<EnemyShip> enemyVectorFleet = {};
    enemyVectorFleet.push_back(EnemyShip(4, 3, 8));
    enemyVectorFleet.push_back(EnemyShip(4, 8, 12));
    enemyVectorFleet.push_back(EnemyShip(6, 8, 10));
    enemyVectorFleet.push_back(EnemyShip(4, 3, 8));
    enemyVectorFleet.push_back(EnemyShip(5, 8, 12));
    enemyVectorFleet.push_back(EnemyShip(2, 3, 5));

    for (EnemyShip e : enemyVectorFleet)
    {
        std::cout << e.volume() << "\n";
    }
    std::cout << "Selection sort \n";
    eSelectionProcessor.sort(enemyVectorFleet);
    for (EnemyShip e : enemyVectorFleet)
    {
        std::cout << e.volume() << "\n";
    }
}

int main(int argc, char *argv[])
{

    sorting();
    
    return 0;
}