/**
 * A hash table-based implementation of the Set interface.
 *
 * @author David
 * @version 2024-07-01
 */
#pragma once
#include "Set.h"
#include <stdexcept>

template <typename T>
class HashSet : public Set<T>
{
    // TODO private List<T>[] table;
public:
    /**
     * Creates a hash table with the given capacity (amount of buckets).
     *
     * @throws IllegalArgumentException if capacity <= 0.
     */
    HashSet(int capacity)
    {
        if (capacity <= 0)
        {
            //TODO
            throw std::invalid_argument {"capacity must be a positive, non-zero value! Provided: " + capacity};
        }

        // We want to do the following:
        //
        //     table = new LinkedList<String>[capacity];
        //
        // However, that won't compile ("generic array creation")
        // since Java generics and arrays don't get along very well.
        // Instead we need to do the following:
        //
        //     table = new LinkedList[capacity];
        //
        // The above will compile, but with a warning. The proper
        // approach is to document why the warning can be safely
        // ignored and then suppress the warning. Thus:

        /*
         * This array will contain only LinkedList<T>
         * instances, all created in the add method. This
         * is sufficient to ensure type safety.
         */
        //TODO
        // @SuppressWarnings("unchecked") // for this declaration only
        //     List<T>[] t = new LinkedList[capacity];

        // table = t;
    }

    /**
     * Adds the given element to the set.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to add to the set.
     * @return true if the set did not contain the element, otherwise false.
     */
    bool add(const T& elem) override
    {
        //throw new UnsupportedOperationException("Not implemented!");
    }

    /**
     * Removes the given element from the dictionary, if it is present.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to remove from the set.
     * @return true if the set contained the element, false otherwise.
     */
    bool remove(const T& elem) override
    {
        //throw new UnsupportedOperationException("Not implemented!");
    }

    /**
     * Check if an element is in the Set.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to look for.
     * @return true if the element is in the set, false otherwise.
     */
    bool contains(const T& elem) const override
    {
        //throw new UnsupportedOperationException("Not implemented!");
    }

    /**
     * Returns the number of elements in this set.
     *
     * Complexity: O(1) expected time.
     *
     * @return The amount of elements in this set.
     */
    int size() const override
    {
        //throw new UnsupportedOperationException("Not implemented!");
    }
};