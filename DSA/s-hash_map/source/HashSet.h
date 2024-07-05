/**
 * A hash table-based implementation of the Set interface.
 *
 * @author David
 * @version 2024-07-01
 */
#pragma once
#include "Set.h"
#include "LinkedList.h"
#include <stdexcept>
/**
 * @class HashSet
 * @brief A template class implementing a HashSet with a raw array of LinkedLists as table.
 * @tparam T The type of elements stored in the list.
 */
template <typename T>
class HashSet : public Set<T>
{
public:
    /**
     * Creates a hash table with the given capacity (amount of buckets).
     *
     * @throws IllegalArgumentException if capacity <= 0.
     */
    HashSet(const int capacity);
    ~HashSet();
    /**
     * Adds the given element to the set.
     *
     * @brief O(1) expected time. Use the `std::hash<T>` class to create the hash code
     *
     * @param elem An element to add to the set.
     * @return true if the set did not contain the element, otherwise false.
     */
    bool add(const T &elem) override;

    /**
     * Removes the given element from the dictionary, if it is present.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to remove from the set.
     * @return true if the set contained the element, false otherwise.
     */
    bool remove(const T &elem) override;

    /**
     * Check if an element is in the Set.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to look for.
     * @return true if the element is in the set, false otherwise.
     */
    bool contains(const T &elem) const override;

    /**
     * Returns the number of elements in this set.
     *
     * Complexity: O(1) expected time.
     *
     * @return The amount of elements in this set.
     */
    size_t size() const override;

private:
    LinkedList<T> *m_table = nullptr;
    size_t m_size = 0;
    size_t m_bucketsCount = 0;
    float m_tableLoad = 0.0f;
    const float LOAD_FACTOR = 0.75f;
    std::hash<T> m_hasher;      //* STD hashing function
    std::equal_to<T> m_equalTo; //* STD comparate function

    void resize(const size_t &newSize);
};

//* Implementation

template <typename T>
HashSet<T>::HashSet(const int capacity) : m_bucketsCount(capacity)
{
    if (capacity <= 0)
        throw std::invalid_argument{"capacity must be a positive, non-zero value!"};

    //? Recall the capacity of a Raw array can change.
    m_table = new LinkedList<T>[capacity];
    std::cout << "Size of: " << sizeof(T) << '\n';
    m_bucketsCount = capacity;
    m_tableLoad = m_size / m_bucketsCount;
};

template <typename T>
HashSet<T>::~HashSet()
{
    delete[] m_table;
};

//* Member functions

template <typename T>
bool HashSet<T>::add(const T &elem)
{
    auto code = m_hasher(elem) % m_bucketsCount;
    std::cout << "Code hashed: " << code << "\n";

    if (code >= m_bucketsCount || m_tableLoad > LOAD_FACTOR)
        resize(code);

    try
    {
        if (m_equalTo(m_table[code].getFirst(), elem))
        {
            std::cout << "Element aready in the HashTable\n";
            return false;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << "\n";
        m_table[code].addLast(elem);
        m_size++;
        m_tableLoad = (float)m_size / (float)m_bucketsCount;
        std::cerr << m_table[code].getFirst() << " <- added to the HashTable, table load: " << m_tableLoad << '\n';
    }
    return true;
}

// TODO
template <typename T>
void HashSet<T>::resize(const size_t &newSize)
{
    std::cout << "Need to re-size\n";
    LinkedList<T> *newTable = new LinkedList<T>[newSize * 2];
    delete[] m_table;
}

template <typename T>
bool HashSet<T>::remove(const T &elem)
{
    if (!contains(elem))
        return false;

    auto code = m_hasher(elem) % m_bucketsCount;
    m_table[code].removeFirst();
    return true;
}

//TODO the current code does not account for resolved collisions
template <typename T>
bool HashSet<T>::contains(const T &elem) const
{
    auto code = m_hasher(elem) % m_bucketsCount;
    if(code >= m_bucketsCount)
        return false;

    //std::cout << m_table[code].getFirst() << " the element, ";
    return m_table[code].size() != 0 ? m_equalTo(m_table[code].getFirst(), elem) : false;
}

template <typename T>
size_t HashSet<T>::size() const
{
    return m_size;
}