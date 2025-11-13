#include "Warrior.h"

Warrior::Warrior(char type, size_t level) : m_type(type), m_level(level) {}

Warrior::Warrior(const Warrior &other)
{
    m_type = other.getType();
    m_level = other.getLevel();
}

Warrior::~Warrior()
{
}

int Warrior::compareTo(const Warrior &other) const
{
    if (m_level < other.getLevel())
        return -1;
    if (m_level > other.getLevel())
        return 1;
    return 0;
}

bool Warrior::operator==(const Warrior &other) const
{
    return (m_level == other.getLevel()) && (m_type == other.getType());
}

char Warrior::getType() const
{
    return m_type;
}
size_t Warrior::getLevel() const
{
    return m_level;
}
std::string Warrior::toString() const {
    std::ostringstream oss;
    oss << "W-" << m_type << "" << m_level;
    return oss.str();
}

std::ostream &operator<<(std::ostream &s, const Warrior &w)
{
    return s << "Warrior " << w.getType() << w.getLevel() << '\n';
}