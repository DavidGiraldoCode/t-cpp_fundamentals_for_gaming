#include "EnemySelectionProcessor.h"

EnemySelectionProcessor::EnemySelectionProcessor() {}

EnemySelectionProcessor::~EnemySelectionProcessor() 
{
    std::cout << "EnemySelectionProcessor Destroied \n";
}

void EnemySelectionProcessor::sort(EnemyShip* enemiesArray, size_t size) 
{
    // TODO Implement Selection Sort for dynamically allocated array
    /**
     * Go through the array, starting with the assumption that the first element is the smallest
     * Compare the assumption with the element to the right, keep comparing until 
     * it finds the new smallest or reaches the end of the collection.
     * If there is a new smallest Swap the positions.
     * 
     */
    int smallestPosition = 0;
    for(size_t i = 0; i < size; i ++)
    {
        smallestPosition = i;
        for(size_t j = i + 1; j < size; j++)
        {
            if(enemiesArray[j].compareTo(enemiesArray[smallestPosition]) == -1)
            {
                smallestPosition = j;
            }
        }
        EnemyShip temp = enemiesArray[i]; // This object's destructor will be called once the functions ends
        enemiesArray[i] = enemiesArray[smallestPosition];
        enemiesArray[smallestPosition] = temp;
    }

};

void EnemySelectionProcessor::sort(std::vector<EnemyShip>& enemiesList) 
{
    int smallestPosition = 0;
    for (size_t i = 0; i < enemiesList.size(); i ++)
    {
        smallestPosition = i;
        for(size_t j = i + 1; j < enemiesList.size(); j++)
        {
            if(enemiesList[j].compareTo(enemiesList[smallestPosition]) == -1)
            {
                smallestPosition = j;
            }
        }
        EnemyShip temp = enemiesList[i];
        enemiesList[i] = enemiesList[smallestPosition];
        enemiesList[smallestPosition] = temp;
    }
};