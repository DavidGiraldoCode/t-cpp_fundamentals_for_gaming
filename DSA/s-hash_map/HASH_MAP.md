# Hash Map - Abstract Data Stucture

The mathematical abstract data structure of a Map is the Set. Which in a collection of unique elements. Meaning, a Set does NOT allows duplicates. In programming, Maps use a _key-value_ pair to map an `element` or `value` to a unique inditifyer called `key`.

The average time complexity of retrieving an element in a map is:
$$ Map(n) = O(1)$$

Because as in raw arrays, as long as we know the `index` or the `key`, there is no need to traverse the collection. Therefore, the underlying data type we use to implements Maps are arrays, with some things to consider.

## Implementation

1. Codification: Transform / encode any complex object into a simple _Integer_
2. Compression: Reduce the encoded _Interger_ into the range of the array, other wise increase the size of the array.
3. Collissions: Resolve the cases in which completly different objects end up with the same key, it both can be stored.