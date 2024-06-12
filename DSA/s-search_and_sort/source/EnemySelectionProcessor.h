#pragma once
#include "EnemyProcessor.h"

class EnemySelectionProcessor : public EnemyProcessor
{
public:
    EnemySelectionProcessor();
    ~EnemySelectionProcessor();

    virtual void sort(EnemyShip* enemiesArray, size_t size) override;
    virtual void sort(std::vector<EnemyShip>& enemiesList) override;
};