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
private:
    LinkedList<T> *table = nullptr;
    size_t m_size = 0;

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
     * @brief O(1) expected time.
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
};

//* Implementation

template <typename T>
HashSet<T>::HashSet(const int capacity) : m_size(capacity)
{
    if (capacity <= 0)
        throw std::invalid_argument{"capacity must be a positive, non-zero value!"};

    table = new LinkedList<T>[capacity];
    m_size = capacity;
};

template <typename T>
HashSet<T>::~HashSet()
{
    delete [] table;
};

//* Member functions

template <typename T>
bool HashSet<T>::add(const T &elem)
{
    return false;
}

template <typename T>
bool HashSet<T>::remove(const T &elem)
{
    return false;
}

template <typename T>
bool HashSet<T>::contains(const T &elem) const
{
    return false;
}

template <typename T>
size_t HashSet<T>::size() const
{
    return false;
}