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
template <class K, typename T>
class HashSet : public Set<T>
{
public:
    /**
     * Creates a hash table with the given capacity (amount of buckets).
     * @throws IllegalArgumentException if capacity <= 0.
     */
    HashSet(const int capacity);
    ~HashSet();
    /**
     * Adds the given element to the set.
     * @brief O(1) expected time. Use the `std::hash<T>` class to create the hash code
     * @param elem An element to add to the set.
     * @return true if the set did not contain the element, otherwise false.
     */
    bool add(const T &elem) override;

    /**
     * Removes the given element from the dictionary, if it is present.
     * Complexity: O(1) expected time.
     * @param elem An element to remove from the set.
     * @return true if the set contained the element, false otherwise.
     */
    bool remove(const T &elem) override;

    /**
     * Check if an element is in the Set.
     * Complexity: O(1) expected time.
     * @param elem An element to look for.
     * @return true if the element is in the set, false otherwise.
     */
    bool contains(const T &elem) const override;

    /**
     * Returns the number of elements in this set.
     * Complexity: O(1) expected time.
     * @return The amount of elements in this set.
     */
    size_t size() const override;

private:
    LinkedList<T> *m_table = nullptr;
    size_t m_size = 0;
    size_t m_bucketsCount = 0;
    float m_tableLoad = 0.0f;
    const float LOAD_FACTOR = 0.75f;
    // std::hash<T> m_hasher;      //* STD hashing function
    K m_hasher;
    std::equal_to<T> m_equalTo; //* STD comparing function, calls the operator==

    size_t hashCode(const T &element);

    /**
     * @brief Creates a new m_table of size: `m_size * 2`
     */
    void resize();

    /**
     * @brief Traverse the Linked List testing that the element is unique and adds it to the tail
     * @param bucket_list The Linked List at the index inside the table
     * @param elem Element to test and add
     * @return True if the element was added, otherwise false.
     */
    bool separateChaning(LinkedList<T> &bucket_content, const T &element);
};

//* Implementation

template <class K, typename T>
HashSet<K, T>::HashSet(const int capacity) : m_bucketsCount(capacity)
{
    if (capacity <= 0)
        throw std::invalid_argument{"capacity must be a positive, non-zero value!"};

    //? Recall the capacity of a Raw array can change.
    m_table = new LinkedList<T>[capacity];
    // std::cout << "Size of: " << sizeof(T) << '\n';
    m_bucketsCount = capacity;
    m_tableLoad = m_size / m_bucketsCount;
};

template <class K, typename T>
HashSet<K, T>::~HashSet()
{
    delete[] m_table;
};

//* Member functions

template <class K, typename T>
bool HashSet<K, T>::add(const T &elem)
{
    if (contains(elem)) // Invariance: check if it is a new element
        return false;
    /**
     * Now that we know is new,
     * 1. Hash the key
     * 1. Check if the bucket is empty,
     * 2. If is not empty, check for collisions
     * */
    auto code = m_hasher(elem) % m_bucketsCount;
    std::cout << "Element " << elem << " / code: " << code << "\n";

    if (m_table[code].size() == 0) // LinkedList at this position is empty
    {
        m_table[code].addLast(elem);
        m_size++;
        m_tableLoad = (float)m_size / (float)m_bucketsCount;
        std::cout << m_table[code].getFirst() << " <- added to the HashTable, index: " << code << " , table load: " << m_tableLoad << '\n';
        if (m_tableLoad > LOAD_FACTOR)
            resize();
        return true;
    }
    else // Bucket not empty
    {
        return separateChaning(m_table[code], elem);
    }
}

template <class K, typename T>
bool HashSet<K, T>::separateChaning(LinkedList<T> &bucket_content, const T &element)
{
    for (size_t i = 0; i < bucket_content.size(); i++)
    {
        if (element == bucket_content.get(i))
            return false;
    }
    std::cout << "Theres was Collission: Element -> " << element
              << " - Bucket content -> " << bucket_content.getFirst() << '\n';
    bucket_content.addLast(element);
    m_size++;
    m_tableLoad = (float)m_size / (float)m_bucketsCount;
    std::cout << "Separete chaning, new element added at the tail: " << bucket_content.getLast()
              << " - Linked list's size grows to : " << bucket_content.size()
              << " , table load: " << m_tableLoad << '\n';
    if (m_tableLoad > LOAD_FACTOR)
        resize();
    return true;
}

template <class K, typename T>
void HashSet<K, T>::resize()
{
    std::cout << "\n ================ Need to re-size ================ \n";
    size_t oldBucketCount = m_bucketsCount;
    m_bucketsCount *= 2;
    m_size = 0;
    m_tableLoad = m_size / m_bucketsCount;
    std::cout << "new capacity: " << m_bucketsCount
              << " reset m_size: " << m_size << "\n";
    LinkedList<T> *tempTable = m_table;
    m_table = new LinkedList<T>[m_bucketsCount];
    for (size_t i = 0; i < oldBucketCount; i++)
    {
        if (tempTable[i].size() != 0)
        {
            for (size_t j = 0; j < tempTable[i].size(); j++)
            {
                add(tempTable[i].get(j));
            }
        }
    }
    std::cout << "\n ------------ Finished re-sizing ------------- \n";
    delete[] tempTable;
}

template <class K, typename T>
size_t HashSet<K, T>::hashCode(const T &element)
{
    auto code = m_hasher(element) % m_bucketsCount;
    return code;
}

template <class K, typename T>
bool HashSet<K, T>::remove(const T &elem)
{
    auto code = hashCode(elem);
    if (m_table[code].size() == 0)
    {
        std::cout << elem << " has not been stored.\n";
        return false;
    }
    else if (m_table[code].size() == 1 && m_equalTo(m_table[code].getFirst(), elem) )
    {
        std::cout << "Found the match, removing...\n";
        m_table[code].removeFirst();
        m_size--;
        m_tableLoad = (float)m_size / (float)m_bucketsCount;
        std::cout << "Size: " << m_size << " Table Load factor: " << m_tableLoad << "\n";
        return true;
    }
    else
    {
        for (size_t i = 0; i < m_table[code].size(); i++)
        {
            if (m_equalTo(m_table[code].get(i), elem))
            {
                std::cout << "Found the match in the linked list\n";
                m_table[code].removeAt(i);
                m_size--;
                m_tableLoad = (float)m_size / (float)m_bucketsCount;
                std::cout << "Size: " << m_size << " Table Load factor: " << m_tableLoad << "\n";
                return true;
            }
        }
        std::cout << elem << " has not been stored (in separate chaining).\n";
        return false;
    }
}

template <class K, typename T>
bool HashSet<K, T>::contains(const T &elem) const
{
    auto code = m_hasher(elem) % m_bucketsCount;
    if (code >= m_bucketsCount)
        return false;

    if (m_table[code].size() == 0)
    {
        return false;
    }
    else // There is a Linked List and probably a chain to traverse
    {
        for (size_t i = 0; i < m_table[code].size(); i++)
        {
            if (m_equalTo(m_table[code].get(i), elem))
            {
                std::cout << "Element " << elem << " is alredy in the Table\n";
                return true;
            }
        }
        return false;
    }
}

template <class K, typename T>
size_t HashSet<K, T>::size() const
{
    return m_size;
}