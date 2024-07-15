#pragma once
template <typename T>
class Comparable
{
public:
    ~Comparable() = default;
    virtual int compareTo(const T &other) const = 0;
    virtual bool operator==(const T &other) const = 0;
};