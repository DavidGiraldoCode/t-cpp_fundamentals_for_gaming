#include "EnemyProcessor.h"

int EnemyProcessor::sequentialSearch(EnemyShip *enemiesArray, size_t size, EnemyShip &target)
{
    for (size_t i = 0; i < size; i++)
    {
        if (target.compareTo(enemiesArray[i]) == 0)
            return i;
    }
    return -1;
}

int EnemyProcessor::sequentialSearch(std::vector<EnemyShip> &enemiesArray, EnemyShip &target)
{
    for (size_t i = 0; i < enemiesArray.size(); i++)
    {
        if (target.compareTo(enemiesArray[i]) == 0)
            return i;
    }
    return -1;
}