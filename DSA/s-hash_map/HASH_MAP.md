# Hash Map - Abstract Data Stucture

The mathematical concept of this abstract data structure is the Set. Which in a collection of unique elements. Meaning, a Set does NOT allows duplicates. There are cases in which the order of the elements matter, for this implementation, I will focus on unoredered maps. In programming, Maps communly use a _key-value_ pair to map an `element` or `value` to a unique inditifyer called `key`. This `key-value` lookups are called **Hash Tables**.

Because we know the `index` or the `key`, as in raw arrays, there is no need to traverse the collection, the lookup happens in `O(1)` constant time. Therefore, the underlying data type we use to implements Maps are arrays, with some things to consider. Maps are efficient but has an implementation cost and complexity. The average time complexity of retrieving an element in a map is:
$$ Map(n) = O(1)$$

The size of the underlying array is called _buckets_. We map each `key` to each _bucket_.

### The key operation on a Map
1. Insert
2. Delete
3. Search

## Implementation

1. Hashing (_Codification_): The hash function transforms / encodes any complex object we decide to use as key into a simple _Integer_ or `size_t` that becomes the `index`, meaning the `key` of that `value`. A hashing function has:
```C++
/**
 * @param Key
 * @return size_t hash code
 * @exception None
*/
```
2. Compression: Reduce the encoded _Interger_ into a `size_t` within the range of the array, other wise increase the size of the array. The compression can be done using Multiplication, Addition or Division.
3. Collissions: In come cases, completly different objects can end up with the same key, we need to resolve these cases so both elements can be stored and retrieved.
    - Lienar Probing: Look for more space
    - Seperate Chaining: Create a second dimension on at that positon to link the element.

## Contracts with Maps and Objects.

Clases must implement their own _hashing_ fucntion to be store on a Map. In Java, all objects have a `hashCode()` function. But in C++, `std::map` and `std::set` use clases that handle hashing and comparing, like the template classes `std::hash<T>` and the `std::equal_to<T>`.