#pragma once
/**
 * An interface describing a generic set. Duplicates are not allowed.
 *
 * @author David
 * @version 2024-07-01
 */
template <typename T>
class Set{
public:
    ~Set() = default;

    /**
     * Adds the given element to the set.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to add to the set.
     * @return true if the set did not contain the element, otherwise false.
     */
    virtual bool add(const T& elem) = 0;

    /**
     * Removes the given element from the dictionary, if it is present.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to remove from the set.
     * @return true if the set contained the element, false otherwise.
     */
    virtual bool remove(const T& elem) = 0;

    /**
     * Check if an element is in the Set.
     *
     * Complexity: O(1) expected time.
     *
     * @param elem An element to look for.
     * @return true if the element is in the set, false otherwise.
     */
    virtual bool contains(const T& elem) const = 0;

    /**
     * Returns the number of elements in this set.
     *
     * Complexity: O(1) expected time.
     *
     * @return The amount of elements in this set.
     */
    virtual size_t size() const = 0;
};