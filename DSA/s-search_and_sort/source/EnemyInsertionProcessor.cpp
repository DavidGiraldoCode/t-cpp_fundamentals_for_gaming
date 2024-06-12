#include "EnemyInsertionProcessor.h"

EnemyInsertionProcessor::EnemyInsertionProcessor() {}

EnemyInsertionProcessor::~EnemyInsertionProcessor()
{
    std::cout << "EnemyInsertionProcessor Destroied \n";
}
// TODO Implement Insertion Sort for dynamically allocated array
void EnemyInsertionProcessor::sort(EnemyShip *enemiesArray, size_t size)
{
    /**
     * Take the second element and compare to the first one,
     * If the left-hand side is greater, swap.
     * Keep comparing to the left until theres no more left to swap
     * Move to the next position to the right.
     */
    int ref = 0;
    for (size_t i = 1; i < size; i++)
    {
        // int j = i - 1;
        ref = i;
        // Go R2L while the left element is bigger than the right element
        while (ref > 0 && enemiesArray[ref - 1].compareTo(enemiesArray[ref]) == 1)
        {
            EnemyShip temp = enemiesArray[ref];
            enemiesArray[ref] = enemiesArray[ref - 1];
            enemiesArray[ref - 1] = temp;
            ref--; // Move to the next left position
        }
    }
};
// TODO Implement Insertion Sort for vector
void EnemyInsertionProcessor::sort(std::vector<EnemyShip> &enemiesList)
{
    int ref = 0;
    for (size_t i = 0; i < enemiesList.size(); i++)
    {
        ref = i;
        while (ref > 0 && enemiesList[ref - 1].compareTo(enemiesList[ref]) == 1)
        {
            EnemyShip tem = enemiesList[ref];
            enemiesList[ref] = enemiesList[ref - 1];
            enemiesList[ref - 1] = tem;
            ref--;
        }
    }
};