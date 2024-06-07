#pragma once
#include <iostream>

class EnemyShip
{
    int m_height;
    int m_width;
    int m_depth;

    public:
        EnemyShip(int height, int width, int depth);
        //? EnemyShip(EnemyShip another) as in Java is not possible
        const int volume();
        const int getHeight();
        const int getWidth();
        const int getDepth();
        //TODO research about how the homologate the @Override from Java
        bool equals(EnemyShip another);
        int hashCode(); 
};