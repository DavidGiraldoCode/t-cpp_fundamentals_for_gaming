#pragma once

template <typename T>
class Stack
{
public:
    ~Stack() = default;
    virtual void push(const T &element) = 0;
    virtual T pop() = 0;
    virtual T& top() = 0;
    virtual const int size() const = 0;
    virtual const bool isEmpty() const = 0;
};