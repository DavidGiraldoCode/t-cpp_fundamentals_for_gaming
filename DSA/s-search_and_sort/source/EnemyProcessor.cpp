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

int EnemyProcessor::binarySearch(EnemyShip *enemiesArray, size_t size, EnemyShip &target)
{
    /**
     * Best case: the target element is at the center
     * Wrost case: There is no such element in the array
     *
     * Algorithm
     * set bounds min = 0 and max = size-1;
     * cursor = (int) max - min / 2 round up.
     * compare the value at curso position, return if equals
     * if target is smaller, update range min = 0 to max = cursor-1
     * if target is bigger, update range min = cursor+1 to max = size-1
     * set cursor at center cursor = max - min / 2;
     * compare the value at cursor+min position with target.
     * repeat this process until the max-min == 0
     */
    int min = 0;
    int max = size - 1;
    int cursor = (int)(max - min) / 2;
    while ((max - min) >= 0)
    {
        std::cout << "min: " << min << " max: " << max << " cursor: " << cursor << "\n";
        if (target.compareTo(enemiesArray[cursor]) == 0)
            return cursor;

        if (target.compareTo(enemiesArray[cursor]) == -1)
        {
            min = 0;
            max = cursor - 1;
        }
        else if (target.compareTo(enemiesArray[cursor]) == 1)
        {
            min = cursor + 1;
            max = size - 1;
        }
        cursor = min + (int)((max - min) / 2);
    }
    return -1;
}

int EnemyProcessor::binarySearch(std::vector<EnemyShip> &enemiesArray, EnemyShip &target)
{
    int min = 0;
    int max = enemiesArray.size() - 1;
    int cursor = (int)(max - min) / 2;
    while ((max - min) >= 0)
    {
        if (target.compareTo(enemiesArray[cursor]) == 0)
            return cursor;
        if (target.compareTo(enemiesArray[cursor]) == 1)
        {
            min = cursor + 1;
            max = enemiesArray.size() - 1;
        }
        else if (target.compareTo(enemiesArray[cursor]) == -1)
        {
            min = 0;
            max = cursor - 1;
        }
        cursor = min + (int)((max - min) / 2);
    }

    return -1;
}