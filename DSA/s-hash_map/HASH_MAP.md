# Hash Map - Abstract Data Stucture

The mathematical concept of this abstract data structure is the Set. Which in a collection of unique elements. Meaning, a Set does NOT allows duplicates. There are cases in which the order of the elements matter, for this implementation, I will focus on unoredered maps. In programming, Maps communly use a _key-value_ pair to map an `element` or `value` to a unique inditifyer called `key`. This `key-value` lookups are called **Hash Tables**.

Because we know the `index` or the `key`, as in raw arrays, there is no need to traverse the collection, the lookup happens in `O(1)` constant time. Therefore, the underlying data type we use to implements Maps are arrays, with some things to consider. Maps are efficient but has an implementation cost and complexity. The average time complexity of retrieving an element in a map is:
$$ Map(n) = O(1)$$ (amortize time).

The places where the `keys` are store are called _buckets_. Which constitute the size of the underlying array.

### The key operation on a Map

1. Insert
2. Delete
3. Search

## Implementation

### 0. The bucket size

As in any other data structure, we need to store the elements of the Hash map somewhere, and the must effective way is inside an array. The position will be the `index` in which each `key` has been mapped by the _hash_ function. But, the number of elements to store in the table is not always known at compile time. So the table (array) will have to reserve some extra space, and eventually re-size.

### 1. Hashing (_Codification_):

The hash function transforms / encodes any complex object we decide to use as key into a simple _Integer_ or `size_t` that becomes the `index`, meaning the `key` of that `value`. A hashing function has:

```C++
/**
 * @param Key
 * @return size_t hash code
 * @exception None
*/
```

In C++ there is a template class called `std::hash<T>` that account for hashing every know value type in C++, except for user-defined types.

### 2. Compression:

Reduce the encoded _Interger_ into a `size_t` within the range of the array. The compression can be done using Multiplication, Addition or Division. A commun way is usign modulo: `hashed_key % size_of_array`.

### 3. Collissions:

In come cases, completly different objects can end up with the same `key`, we need to resolve these cases so both elements can be stored and retrieved.

- **Lienar Probing:** Look for more space on the next position linearly.
- **Separate Chaining:** Create a second dimension on at that positon to link the element.
  `[hashCode] = {(elem1) -> next}, {(elem2) -> next}`
  To make sure a collision has occurred (and no to the same object trying to be inserted), one needs to compare the element to insert and the element inside the table by implementing the `operator==`. One must compare only relevant attribut to avoid uncesarry computations.

```C++
bool operator==(const MyClass &otherObject) const
{
    return this.m_important_attribute == otherObject.m_important_attribute;
}
```

## Contracts with Maps and Objects.

Clases must implement their own _hashing_ function to be store on a Map. In Java, all objects have a `hashCode()` function. But in C++, `std::map` and `std::set` use clases that handle hashing and comparing, like the template classes `std::hash<T>` and the `std::equal_to<T>`.

## Hashing user-define type

When you have a collection of objects from a custom class and want to store them in a HashTable using the object itself as a key, you must define the hash function by overloading the `operator()` inside a `struct` or `class` for that specific type, then use the most representative attributes of the given class. For example:

```C++
struct MyHash
{
    size_t operator()(const MyClass& object) const noexcept
    {
        size_t hash_code_a = std::hash<int>{}(object.attributeA);
        size_t hash_code_b = std::hash<int>{}(object.attributeB);

        //This is a common technique to combine multiple hash values.
        return hash_code_a ^ (hash_code_b << 1);
    }
};
```
The noexcept specifier indicates that the hash function does not throw any exceptions, so there is no need to wrap it inside a try-catch block.

> Recall, Bitwise XOR (^): Compares each bit of the two numbers and returns 1 if the bits are different, and 0 if they are the same. For 1 is 0001 and 2 is 0010, then 1^2 =  0011, which is 3 in decimal.

> Recall, Bitwise Shift Left (<<): Shifts the bits of a number 'n' positions to the left. In binary, 1 is 0001. Shifting it one position to the left gives 0010, which is 2 in decimal.