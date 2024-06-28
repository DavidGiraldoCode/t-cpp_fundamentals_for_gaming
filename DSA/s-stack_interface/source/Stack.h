/**
 * Stack interface to be implemented by a LinkedList class
 * 
 * @author  David Giraldo
 * @version 2024-06-28
 */
#pragma once

template <typename T>
class Stack
{
public:
    ~Stack() = default;
    /**
     * Push an element into the Stack
     *
     * @param element  Any element to add to the Static
     */
    virtual void push(const T &element) = 0;
     /**
     * Removes the last element on the Stack.
     *
     * @return      Copy of the element that was removed
     * @throws      EmptyStackException if the stack is empty
     */
    virtual T pop() = 0;
     /**
     * Returns the reference to the top element.
     *
     * @return      Reference to the element on top
     * @throws      EmptyStackException if the stack is empty
     */
    virtual T& top() const = 0;
    /**
     * Returns the Size of the Stack
     *
     * @return      Number of elements in the Stack
     */
    virtual const int size() const = 0;
    /**
     * Tells whether the Stack is empty or not
     *
     * @return      True is the Stack is empty
     */
    virtual const bool isEmpty() const = 0;
};