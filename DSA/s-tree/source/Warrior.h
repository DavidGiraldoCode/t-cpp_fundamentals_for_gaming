#pragma once
#include "Comparable.h"
#include <iostream>
#include <sstream> // Include this header for std::ostringstream

class Warrior : public Comparable<Warrior>
{
public:
    Warrior() = default;
    Warrior(char type, size_t level);
    Warrior(const Warrior &other);
    //TODO Study Move constuctor

    ~Warrior();
    /**
     * @brief Compares the Warrior's level agains other's
     * @return 1 is the current level is higher, -1 is lower, 0 if equal
    */
    int compareTo(const Warrior &other) const override;
    bool operator==(const Warrior &other) const override;
    char getType() const;
    size_t getLevel() const;
    std::string toString() const;

private:
    size_t m_level = 666;
    char m_type = 'X';
};

// Operator Overloading for Output
std::ostream &operator<<(std::ostream &s, const Warrior &w);
