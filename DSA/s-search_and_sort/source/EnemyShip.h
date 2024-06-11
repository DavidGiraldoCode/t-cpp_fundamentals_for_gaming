#pragma once
#include <iostream>
#include "Comparable.h"

class EnemyShip : public Comparable<EnemyShip>
{
    private:
        int m_height;
        int m_width;
        int m_depth;

    public:
        EnemyShip(int height, int width, int depth);
        ~EnemyShip();
        //? EnemyShip(EnemyShip another) as in Java is not possible
        const int volume();
        const int getHeight();
        const int getWidth();
        const int getDepth();
        //TODO research about how the homologate the @Override from Java
        bool equals(EnemyShip &another);
        int hashCode(); 
        virtual int compareTo(EnemyShip &another) override; //virtual and override are only stated in the declaration file
};