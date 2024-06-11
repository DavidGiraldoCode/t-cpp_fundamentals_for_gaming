#pragma once
#include "EnemyProcessor.h"

class EnemySelectionProcessor : public EnemyProcessor
{
public:
    EnemySelectionProcessor();
    ~EnemySelectionProcessor();

    virtual void sort(int * enemiesArray[]) override;
    virtual void sort(std::vector<EnemyShip> enemiesList) override;
};