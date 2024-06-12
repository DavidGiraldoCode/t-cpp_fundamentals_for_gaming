#pragma once
#include "EnemyProcessor.h"

class EnemyInsertionProcessor : public EnemyProcessor
{
public:
    EnemyInsertionProcessor();
    ~EnemyInsertionProcessor();

    virtual void sort(EnemyShip* enemiesArray, size_t size) override;
    virtual void sort(std::vector<EnemyShip>& enemiesList) override;
};