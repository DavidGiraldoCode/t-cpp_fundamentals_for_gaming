#pragma once
#include "EnemyProcessor.h"

class EnemyInsertionProcessor : public EnemyProcessor
{
public:
    EnemyInsertionProcessor();
    ~EnemyInsertionProcessor();

    virtual void sort(int *enemiesArray[]) override;
    virtual void sort(std::vector<EnemyShip> enemiesList) override;
};