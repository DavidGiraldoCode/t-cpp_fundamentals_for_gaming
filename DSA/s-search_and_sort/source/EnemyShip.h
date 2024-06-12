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
        EnemyShip(const EnemyShip &another);
        ~EnemyShip();
        int volume() const;
        int getHeight() const;
        int getWidth() const;
        int getDepth() const;
        //TODO research about how the homologate the @Override from Java
        bool equals(EnemyShip &another);
        int hashCode(); 
        //Find the natural order of couple of EnemyShips
        virtual int compareTo(EnemyShip &another) override; //virtual and override are only stated in the declaration file
};