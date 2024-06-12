/**
* This abstract class will define a virtual sorting methods 
* so derived classed can implement different approaches
**/
#pragma once //* Always remmeber on all header files.
#include <vector>
#include "EnemyShip.h"

class EnemyProcessor
{
public:
    //? This is an abstract class, therefore it does not have a constructor
    virtual ~EnemyProcessor() = default;
    virtual void sort(EnemyShip* enemiesArray, size_t size) = 0;
    virtual void sort(std::vector<EnemyShip>& enemiesList) = 0;
};