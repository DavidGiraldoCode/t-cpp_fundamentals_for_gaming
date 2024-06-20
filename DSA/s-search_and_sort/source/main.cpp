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
    const size_t FLEET_SIZE = 9;                         // The value that difines the aray most be constant
    EnemyShip *enemyRAWFleet = new EnemyShip[FLEET_SIZE]{//! Dynamically allocated!
                                                         {9,9,9},
                                                         {8,8,8},
                                                         {7,7,7},
                                                         {6,6,6},
                                                         {5,5,5},
                                                         {4,4,4},
                                                         {3,3,3},
                                                         {2,2,2},   
                                                         {1,1,1}};

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

    //std::cout << "My Vector Fleet \n";
    std::vector<EnemyShip> enemyVectorFleet = {};
    enemyVectorFleet.push_back(EnemyShip(4, 3, 8));
    enemyVectorFleet.push_back(EnemyShip(4, 8, 12));
    enemyVectorFleet.push_back(EnemyShip(6, 8, 10));
    enemyVectorFleet.push_back(EnemyShip(4, 3, 8));
    enemyVectorFleet.push_back(EnemyShip(5, 8, 12));
    enemyVectorFleet.push_back(EnemyShip(2, 3, 5));

    for (EnemyShip e : enemyVectorFleet)
    {
        //std::cout << e.volume() << "\n";
    }
    std::cout << "Selection sort \n";
    eSelectionProcessor.sort(enemyVectorFleet);
    for (EnemyShip e : enemyVectorFleet)
    {
        //std::cout << e.volume() << "\n";
    }
}

void insertionSorting()
{
    EnemyInsertionProcessor eInsertionProcessor = EnemyInsertionProcessor();
    const size_t FLEET_SIZE = 9;
    EnemyShip *enemyRAWFleet = new EnemyShip[FLEET_SIZE]{
                                                         {9,9,9},
                                                         {8,8,8},
                                                         {7,7,7},
                                                         {6,6,6},
                                                         {5,5,5},
                                                         {4,4,4},
                                                         {3,3,3},
                                                         {2,2,2},   
                                                         {1,1,1}};

                                                         /*{4, 6, 10},
                                                         {3, 3, 8},
                                                         {4, 8, 12},
                                                         {4, 6, 10},
                                                         {5, 7, 12},
                                                         {1, 8, 12},
                                                         {12, 6, 10},
                                                         {15, 7, 12},
                                                         {2, 3, 5}};*/
                                                         /*{1,1,1},
                                                         {2,2,2},
                                                         {3,3,3},
                                                         {4,4,4},
                                                         {5,5,5},
                                                         {6,6,6},
                                                         {7,7,7},
                                                         {8,8,8},
                                                         {9,9,9}*/

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

    //std::cout << "My Vector Fleet \n";
    std::vector<EnemyShip> enemyVectorFleet = {};
    enemyVectorFleet.push_back(EnemyShip(4, 3, 8));
    enemyVectorFleet.push_back(EnemyShip(4, 8, 12));
    enemyVectorFleet.push_back(EnemyShip(6, 8, 10));
    enemyVectorFleet.push_back(EnemyShip(4, 3, 8));
    enemyVectorFleet.push_back(EnemyShip(5, 8, 12));
    enemyVectorFleet.push_back(EnemyShip(2, 3, 5));

    for (EnemyShip e : enemyVectorFleet)
    {
        //std::cout << e.volume() << "\n";
    }
    std::cout << "Insertion sort \n";
    eInsertionProcessor.sort(enemyVectorFleet);
    for (EnemyShip e : enemyVectorFleet)
    {
        //std::cout << e.volume() << "\n";
    }
}

void linearSearch()
{
    const size_t FLEET_SIZE = 6;
    EnemyShip *enemyRAWFleet = new EnemyShip[FLEET_SIZE]{
        {2, 3, 8},
        {1, 3, 4},
        {2, 7, 4},
        {8, 3, 8},
        {1, 3, 4},
        {1, 6, 14}

    };
    std::vector<EnemyShip> enemyFleet = {};
    enemyFleet.push_back(EnemyShip(2, 3, 8));
    enemyFleet.push_back(EnemyShip(1, 3, 4));
    enemyFleet.push_back(EnemyShip(2, 7, 8));
    enemyFleet.push_back(EnemyShip(1, 3, 4));
    enemyFleet.push_back(EnemyShip(1, 6, 14));

    EnemyShip enemy = EnemyShip(2, 7, 4);

    EnemyInsertionProcessor eInsertionProcessor = EnemyInsertionProcessor();
    std::cout << "Testing precense in RAW array: \n";
    std::cout << eInsertionProcessor.sequentialSearch(enemyRAWFleet, FLEET_SIZE, enemy) << "\n";
    std::cout << "Testing precense in vector: \n";
    std::cout << eInsertionProcessor.sequentialSearch(enemyFleet, enemy) << "\n";
}

// TODO this binary search is lacking correctness, check leetcode devlogs to update
void binarySearch()
{
    std::cout << "My RAW Fleet \n";
    EnemyInsertionProcessor eInsertionProcessor = EnemyInsertionProcessor();
    EnemyShip target = EnemyShip(9, 16, 14);
    std::vector<EnemyShip> enemyFleet = {};
    const size_t FLEET_SIZE = 15;
    EnemyShip *enemyRAWFleet = new EnemyShip[FLEET_SIZE]{
        {2, 3, 4},
        {7, 3, 4},
        {2, 7, 7},
        {2, 3, 8},
        {11, 3, 4},
        {2, 7, 4},
        {8, 3, 8},
        {1, 3, 4},
        {2, 11, 4},
        {8, 13, 9},
        {1, 3, 14},
        {2, 11, 4},
        {9, 9, 9},
        {9, 3, 4},
        {9, 16, 14}};
    std::cout << "Insertion sort on RAW \n";
    eInsertionProcessor.sort(enemyRAWFleet, FLEET_SIZE);
    for (size_t i = 0; i < FLEET_SIZE; i++)
    {
        std::cout << enemyRAWFleet[i].volume() << "\n";
        enemyFleet.push_back(enemyRAWFleet[i]);
    }
    std::cout << "Binary search: The target " << target.volume() << " is at index: \n"
              << eInsertionProcessor.binarySearch(enemyRAWFleet, FLEET_SIZE, target) << " in the RAW array \n";
    // std::cout << ((int)1/2) + 1 << " - \n";

    delete[] enemyRAWFleet;

    std::cout << "Binary search: The target " << target.volume() << " is at index: \n"
              << eInsertionProcessor.binarySearch(enemyFleet, target) << " in the vector array \n";
}

int main(int argc, char *argv[])
{
    selectionSorting();
    insertionSorting();

    return 0;
}