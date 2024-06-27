#pragma once
#include <iostream>
#include <stdexcept>
#include "Stack.h"

template <typename T>
class LinkedList : public Stack<T>
{
private:
    size_t m_size;
    class ListElement
    {
    public:
        T element;
        ListElement *next = nullptr;
        ListElement *previous = nullptr;
        ListElement(const T &data)
        {
            element = data;
        }
        ~ListElement()
        {
            next = nullptr;
            previous = nullptr;
            std::cout << "ListElement with element " << element << " destroyed\n";
        }
    };

    ListElement *first;
    ListElement *last;

public:
    LinkedList();
    LinkedList(const LinkedList &other);
    ~LinkedList();
    //* ============================================================ STACK implementations

    //* ============================================================
    /**
     * Inserts the given element at the beginning of this list.
     *
     * @param element An element to insert into the list.
     */
    void addFirst(const T &node);
    /**
     * Inserts the given element at the end of this list.
     *
     * @param element An element to insert into the list.
     */
    void addLast(const T &node);

    /**
     * @return The head of the list.
     * @throws NoSuchElementException if the list is empty.
     */
    T &getFirst() const;

    /**
     * @return The tail of the list.
     * @throws NoSuchElementException if the list is empty.
     */
    T &getLast() const;

    /**
     * Returns an element from a specified index.
     *
     * @param index A list index.
     * @return The element at the specified index.
     * @throws IndexOutOfBoundsException if the index is out of bounds.
     */
    T &get(const size_t target) const;
    /**
     * Removes the first element from the list.
     *
     * @return The removed element.
     * @throws NoSuchElementException if the list is empty.
     */
    T removeFirst();
    /**
     * Removes the last element from the list.
     *
     * @return The removed element.
     * @throws NoSuchElementException if the list is empty.
     */
    T removeLast();
    /**
     * Removes all of the elements from the list.
     */
    void clear();
    /**
     * @return The number of elements in the list.
     */
    int size() const;
    /**
     * Note that by definition, the list is empty if both first and last
     * are null, regardless of what value the size field holds (it should
     * be 0, otherwise something is wrong).
     *
     * @return <code>true</code> if this list contains no elements.
     */
    bool isEmpty() const;
    //! Convert to String will be pending.
     /**
     * Creates a string representation of this list. The string
     * representation consists of a list of the elements enclosed in
     * square brackets ("[]"). Adjacent elements are separated by the
     * characters ", " (comma and space). Elements are converted to
     * strings by the method toString() inherited from Object.
     *
     * Examples:
     *  "[1, 4, 2, 3, 44]"
     *  "[]"
     *
     * @return A string representing the list.
     */
    // public String toString() {
    //     // TODO
    //     return null;
    // }
};

template <typename T>
LinkedList<T>::LinkedList() : first(nullptr), last(nullptr), m_size(0)
{
    std::cout << "empty LinkedList created \n";
    first = nullptr;
    last = nullptr;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList &other) : first(nullptr), last(nullptr), m_size(0)
{
    /**
     * While throwing the exception is valid, copying an empty list is legit
     * throw std::logic_error{"The List is empty, nothing to copy"};
     */
    if (other.size() != 0)
    {
        first = new ListElement(other.getFirst());
        last = first;
        m_size = other.size();
        std::cout << "Copying " << first->element << "\n";

        for (size_t i = 1; i < other.size(); i++)
        {
            ListElement *copy = new ListElement(other.get(i));
            copy->previous = last;
            last->next = copy;
            last = copy;
            std::cout << "Copying " << copy->element << "\n";
        }
    }
    else
    {
        std::cout << "empty copy of LinkedList created \n";
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    ListElement *current = first;
    while (current != nullptr)
    {
        ListElement *next = current->next;
        delete current;
        current = next;
    }
    std::cout << "LinkedList destroyed \n";
}

template <typename T>
void LinkedList<T>::addFirst(const T &node)
{
    ListElement *element = new ListElement(node);
    if (!first && m_size == 0) // Invariance: Check if the lit is empty
    {
        first = element;
        last = element;
    }
    else
    {
        element->next = first;
        first->previous = element;
        first = element;
    }
    m_size++;
}

template <typename T>
void LinkedList<T>::addLast(const T &node)
{
    ListElement *element = new ListElement(node);
    if (!last && m_size == 0) // Invariance, check if the list is empty
    {
        last = element;
        first = element;
    }
    else
    {
        last->next = element;
        element->previous = last;
        last = element;
    }
    m_size++;
}

template <typename T>
T &LinkedList<T>::getFirst() const
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to retrieve"};
    else
        return first->element;
}

template <typename T>
T &LinkedList<T>::getLast() const
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to retrieve"};
    else
        return last->element;
}

template <typename T>
T &LinkedList<T>::get(const size_t target) const
{
    // invariance
    /**
     * Notice that target is of size_t that is an unsigned integer type,
     * meaning it can only represent non-negative numbers (zero and positive integers)
     * */
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to retrieve"};
    if (target > m_size - 1)
        throw std::logic_error{"Index out of bounce"};

    if (target == 0)
        return first->element;
    else if (target == m_size - 1)
        return last->element;

    int i = 1;
    ListElement *node = first;
    while (node != nullptr && i <= target)
    {
        ListElement *temp = node->next; // Start on the second becase we avoid the looping if target is 0.
        node = temp;
        i++;
    }
    return node->element;
}

/**
 * Notice that here we return a COPY not a refence to the removed element
 * Because the removed element no longer exist in memory, and its reference
 * has been deallocated from memory
 */
template <typename T>
T LinkedList<T>::removeFirst()
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to remove"};

    T removedElement = first->element;
    if (m_size == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        ListElement *temp = first->next;
        temp->previous = nullptr;
        delete first;
        first = temp;
    }

    m_size--;
    return removedElement;
}

template <typename T>
T LinkedList<T>::removeLast()
{
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to remove"};

    T removedElement = last->element;
    if (m_size == 1)
    {
        delete first;
        first = nullptr;
        last = nullptr;
    }
    else
    {
        ListElement *temp = last->previous;
        temp->next = nullptr;
        delete last;
        last = temp;
    }

    m_size--;
    return removedElement;
}

template <typename T>
void LinkedList<T>::clear()
{
    if (m_size == 0)
        throw std::logic_error{"The list is already empty"};
    std::cout << "Clearing list\n";
    ListElement *node = first;
    while (node != nullptr)
    {
        std::cout << node->element << " deleting.. \n";
        ListElement *temp = node->next;
        delete node;
        node = temp;
    }
    first = nullptr;
    last = nullptr;
    m_size = 0;
}

template <typename T>
int LinkedList<T>::size() const
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
    return !first && !last;
}