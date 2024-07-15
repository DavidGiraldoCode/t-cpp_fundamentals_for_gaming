#pragma once
#include "Comparable.h"
#include <iostream>

class Warrior : public Comparable<Warrior>
{
public:
    Warrior() = default;
    Warrior(const Warrior &other);
    ~Warrior();

    int compareTo(const Warrior &other) const override;
    bool operator==(const Warrior &other) const override;
private:
    size_t m_level = 0;
    char type = 'A';
};