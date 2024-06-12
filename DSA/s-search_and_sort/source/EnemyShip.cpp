#include "EnemyShip.h"

EnemyShip::EnemyShip(int height, int width, int depth)
    : m_height(height),
      m_width(width),
      m_depth(depth)
{
    //std::cout << "EnemyShip ready" << "\n";
}

EnemyShip::EnemyShip(const EnemyShip &other) : m_height(other.getHeight()),
                                               m_width(other.getWidth()),
                                               m_depth(other.getDepth()) {}

EnemyShip::~EnemyShip()
{
    //std::cout << "Bye!" << "\n";
}

int EnemyShip::volume() const
{
    return m_height * m_width * m_depth;
}

int EnemyShip::getHeight() const
{
    return m_height;
}

int EnemyShip::getWidth() const
{
    return m_width;
}

int EnemyShip::getDepth() const
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
    if (volume() < another.volume())
        return -1;
    else if (volume() == another.volume())
        return 0;
    else
        return 1;
}