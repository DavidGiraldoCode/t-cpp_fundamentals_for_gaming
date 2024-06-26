#pragma once
template <typename T>
//* pure-virtual class
class Comparable //Interface
{
public:
    virtual ~Comparable() = default;
    //* pure-virtual method
    virtual int compareTo(T &another) = 0; // NOT <T> another
};