#pragma once
#include <iostream>

template <typename T>
class LinkedList
{
private:
    size_t m_size;
    // T *m_list = nullptr;

    // template <typename T>
    class ListElement // Static not permited
    {
    public:
        T element;
        ListElement &next = nullptr;
        ListElement &previous = nullptr;
        ListElement(const T &data) 
        {
            element = data;
        }
        ~ListElement() {}
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
    void addLast(T &node);

    /**
     * @return The head of the list.
     * @throws NoSuchElementException if the list is empty.
     */
    T &getFirst();

    /**
     * @return The tail of the list.
     * @throws NoSuchElementException if the list is empty.
     */
    T &getLast();

    /**
     * Returns an element from a specified index.
     *
     * @param index A list index.
     * @return The element at the specified index.
     * @throws IndexOutOfBoundsException if the index is out of bounds.
     */
    T &get(const size_t index);
    /**
     * Removes the first element from the list.
     *
     * @return The removed element.
     * @throws NoSuchElementException if the list is empty.
     */
    T &removeFirst();
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
    bool isEmpty();
    //! Convert to String will be pending.
};

template <typename T>
LinkedList<T>::LinkedList() : first(nullptr), last(nullptr), m_size(0)
{
    // m_list = new T;
    std::cout << "empty LinkedList created \n";
    first = nullptr;
    last = nullptr;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    // m_list = new T;
    std::cout << "empty LinkedList destroyed \n";
    delete first;
    delete last;
}

template <typename T>
void LinkedList<T>::addFirst(const T &node)
{
    ListElement *element = new ListElement(node);
    //element->next = first;
    //first = element;
    m_size++;
}

template <typename T>
int LinkedList<T>::size() const // TODO review
{
    return m_size;
}

template <typename T>
bool LinkedList<T>::isEmpty() // TODO review
{
    return first && last;
}