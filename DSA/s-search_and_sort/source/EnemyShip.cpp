#include "EnemyShip.h"

EnemyShip::EnemyShip(int height, int width, int depth)
    : m_height(height),
      m_width(width),
      m_depth(depth)
{
    std::cout << "EnemyShip ready" << "\n";
}

EnemyShip::EnemyShip(EnemyShip &another)
{
    m_height = another.getHeight();
    m_width = another.getWidth();
    m_depth = another.getDepth();
}

EnemyShip::~EnemyShip()
{
    std::cout << "Bye!" << "\n";
}

const int EnemyShip::volume()
{
    return m_height * m_width * m_depth;
}

const int EnemyShip::getHeight()
{
    return m_height;
}

const int EnemyShip::getWidth()
{
    return m_width;
}

const int EnemyShip::getDepth()
{
    return m_depth;
}

bool EnemyShip::equals(EnemyShip &another)
{
    // TODO implement based on the Java file.
    return true;
}

int EnemyShip::hashCode()
{
    int result = 13;
    result = 31 * result + m_height;
    result = 31 * result + m_width;
    result = 31 * result + m_depth;
    return result;
}

int EnemyShip::compareTo(EnemyShip &another)
{
    if (volume() < another.volume()) return -1;
    else if (volume() == another.volume()) return 0;
    else return 1;
}