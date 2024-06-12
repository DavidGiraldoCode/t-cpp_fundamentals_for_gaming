// g++ -std=c++20 *.cpp -o myProgram && ./myProgram
#include <iostream>
#include "EnemyShip.h"
#include "EnemyProcessor.h"
#include "EnemySelectionProcessor.h"
#include "EnemyInsertionProcessor.h"

// TODO use Resource Acquisition is Initialization (RAII) pattern

void selectionSorting()
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

void insertionSorting()
{
    EnemyInsertionProcessor eInsertionProcessor = EnemyInsertionProcessor();
    const size_t FLEET_SIZE = 9;
    EnemyShip *enemyRAWFleet = new EnemyShip[FLEET_SIZE]{
        {2, 3, 4},
        {7, 3, 4},
        {2, 7, 7},
        {2, 3, 8},
        {1, 3, 4},
        {2, 7, 4},
        {8, 3, 8},
        {1, 3, 4},
        {1, 6, 14}};

    std::cout << "My RAW Fleet \n";
    for (size_t i = 0; i < FLEET_SIZE; i++)
    {
        std::cout << enemyRAWFleet[i].volume() << "\n";
    }

    std::cout << "Insertion sort \n";
    eInsertionProcessor.sort(enemyRAWFleet, FLEET_SIZE);
    for (size_t i = 0; i < FLEET_SIZE; i++)
    {
        std::cout << enemyRAWFleet[i].volume() << "\n";
    }

    delete[] enemyRAWFleet;

    std::cout << "My Vector Fleet \n";
    std::vector<EnemyShip> enemyVectorFleet = {};
    enemyVectorFleet.push_back(EnemyShip(2, 3, 4));
    enemyVectorFleet.push_back(EnemyShip(2, 6, 4));
    enemyVectorFleet.push_back(EnemyShip(2, 8, 4));
    enemyVectorFleet.push_back(EnemyShip(2, 3, 2));
    enemyVectorFleet.push_back(EnemyShip(2, 9, 4));

    for (EnemyShip e : enemyVectorFleet)
    {
        std::cout << e.volume() << "\n";
    }
    std::cout << "Insertion sort \n";
    eInsertionProcessor.sort(enemyVectorFleet);
    for (EnemyShip e : enemyVectorFleet)
    {
        std::cout << e.volume() << "\n";
    }
}

int main(int argc, char *argv[])
{
    //selectionSorting();
    //insertionSorting();

    return 0;
}