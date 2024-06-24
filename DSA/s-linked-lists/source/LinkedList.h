#pragma once
#include <iostream>
#include <stdexcept>

template <typename T>
class LinkedList
{
private:
    size_t m_size;
    // T *m_list = nullptr;

    // template <typename T>
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
            std::cout << "ListElement destroyed\n";
        }
    };

    ListElement *first;
    ListElement *last;

public:
    int val;
    explicit LinkedList(); // TODO review more about explicit
    ~LinkedList();
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
};

template <typename T>
LinkedList<T>::LinkedList() : first(nullptr), last(nullptr), m_size(0)
{
    std::cout << "empty LinkedList created \n";
    first = nullptr;
    last = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // m_list = new T;
    std::cout << "LinkedList destroyed \n";
    delete first;
    delete last;
}

template <typename T>
void LinkedList<T>::addFirst(const T &node)
{
    ListElement *element = new ListElement(node);
    if (!first)
    {
        first = element;
        last = element;
        // addLast(element);
    }
    else
    {
        element->next = first;
        first = element;
    }
    m_size++;
}

template <typename T>
void LinkedList<T>::addLast(const T &node)
{
    ListElement *element = new ListElement(node);
    if (!last)
    {
        last = element;
        first = element;
        // addFirst(element);
    }
    else
    {
        last->next = element;
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
    ListElement *node = first->next;
    while (node != nullptr && i < target)
    {
        ListElement *temp = node->next;
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
    // invariance
    if (m_size == 0)
        throw std::logic_error{"The list is empty, nothing to remove"};
    ListElement *temp = first->next;
    T removedElement = first->element;
    delete first;
    first = temp;
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
        m_size--;
    }
    first = nullptr;
    last = nullptr;
    m_size = 0;
}

template <typename T>
int LinkedList<T>::size() const // TODO review
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() const // TODO review
{
    return !first && !last;
}