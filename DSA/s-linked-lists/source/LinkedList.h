#pragma once
#include <iostream>

template <typename T> 

class LinkedList
{
    size_t m_size = 0;
    T * m_list;

private:
    class ListElement //Static not permited
    {
        public:
        T data;
        ListElement & next;
        ListElement & previous;
        ListElement(T data);
        ~ListElement();
    };

    ListElement first;
    ListElement last;
public:
    LinkedList();
    ~LinkedList();
    /**
     * Inserts the given element at the beginning of this list.
     *
     * @param element An element to insert into the list.
     */
    void addFirst(T node);
    /**
     * Inserts the given element at the end of this list.
     *
     * @param element An element to insert into the list.
     */
    void addLast(T node);
    /**
     * @return The head of the list.
     * @throws NoSuchElementException if the list is empty.
     */
    T& getFirst();
    /**
     * @return The tail of the list.
     * @throws NoSuchElementException if the list is empty.
     */
    T& getLast();
    /**
     * Returns an element from a specified index.
     *
     * @param index A list index.
     * @return The element at the specified index.
     * @throws IndexOutOfBoundsException if the index is out of bounds.
     */
    T& get(size_t index);
    /**
     * Removes the first element from the list.
     *
     * @return The removed element.
     * @throws NoSuchElementException if the list is empty.
     */
    T& removeFirst();
    /**
     * Removes all of the elements from the list.
     */
    void clear();
    /**
     * @return The number of elements in the list.
     */
    int size();
     /**
     * Note that by definition, the list is empty if both first and last
     * are null, regardless of what value the size field holds (it should
     * be 0, otherwise something is wrong).
     *
     * @return <code>true</code> if this list contains no elements.
     */
    bool isEmpty();
    //! Convert to String will be pending.
};