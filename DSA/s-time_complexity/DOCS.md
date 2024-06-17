### Order of growth

- Logarithmic = log<sub>2</sub>(n)
- Linear = n
- Linearithmic = n log n
- Quadratic = n<sup>2</sup>
- Cubic = n<sup>3</sup>
- Exponential = 2<sup>n</sup>
- Factorial = n!
*logarithms are base 2 when you see log n.

| Size / complexity |     log n     |       n       |    n log n    |  n<sup>2</sup>   |  n<sup>3</sup>   |   2<sup>n</sup>  |      n!          |
|-------------------|---------------|---------------|---------------|------------------|------------------|------------------|------------------|
| 1                 | 0             | 1             | 0             | 1                | 1                | 2                | 1                |
| 10                | 3.21          | 10            | 32.2          | 100              | 1000             | 1024             | 36288e2          |
| 100               | 6.64          | 100           | 664.3         | 10000            | 1e6              | 1e30             | 9e157            |
| 1000              | 9.966         | 1000          | 9966          | 1e6              | 1e9              | 1e301            | 4e2567           |
| 10000             | 13.28         | 10000         | 132877.1      | 1e8              | 1e12             | 1e3010           | 2e35659          |
| 100000            | 16.61         | 100000        | 1e6           | 1e10             | 1e15             | 1e30102          | 2e456573         |
| 1000000           | 19.93         | 1000000       | 1e7           | 1e12             | 1e18             | 1e301029         | 8e5565708        |

Computed value using [Wolfram Alpha](https://www.wolframalpha.com).

Base on the table above, the following functions can be organized from the smallest to the biggest running time order of growth

f4(n) = n + 100
f3(n) = n log n
f1(n) = n<sup>1.5</sup>
f5(n) = 2<sup>n</sup>
f2(n) = 10<sup>n</sup>


### Size of n that an algorithm can be solve on a given time 
Time given in nanoseconds (1e-9 seconds)

| T(n)          | 1 second | 1 minute |  1 hour  |  1 day   |  1 year  |
| --------------|----------|----------|----------|----------|----------|
| log n         | 1e9      |          | &#x221e; |          |          |
| n             | 1e9      | 6e10     | 3.6e12   | 8.64e13  | 3.154e16 |
| n log n       |          |          | 9.8e10   |          |          |
| n<sup>2</sup> |          |          | 1.8e6    |          |          |
| n<sup>3</sup> |          |          | 15326    |          |          |
| 2<sup>n</sup> |          |          | 41       |          |          |
| n!            |          |          | 15       |          |          |
<br/>

# O-estimations in for loops
Let us give an O-estimation, as a function of n, of the worst-case time
complexity of the following algorithms:
***
```
Algorithm Loop1(n):    cost operations
   a = 0                C1  n
   for i = 1 to n       C2  n
      a += i            C3  n-1 
```

$$
\begin{align*}
T(n) &= C_1 \cdot n + C_2 \cdot n + C_3 \cdot (n-1) \\
T(n) &= C_1 \cdot n + C_2 \cdot n + C_3 \cdot n - C_3 \\
T(n) &= (C_1 + C_2 + C_3) \cdot n - C_3 \\
T(n) &= a \cdot n - b
\end{align*}
$$

where `n` is the dominant term. Thus, the linear order of growth is `O(n)`.
***
```
Algorithm Loop2(n):   cost operations
   b = 1                C1 n
   for i = 1 to 4n      C2 4n
      b++               C3 4n-1 
```

$$
\begin{align*}
T(n) &= C_1 \cdot n + C_2 \cdot 4n + C_3 \cdot (4 \cdot n-1) \\
T(n) &= C_1 \cdot n + C_2 \cdot 4n + 4 \cdot C_3 \cdot n - C_3 \\
T(n) &= (C_1 + C_2 + 4 \cdot C_3) \cdot n - C_3 \\
T(n) &= a \cdot n - b
\end{align*}
$$

Where `n` is the dominant term, it thus has a linear order of growth `O(n).`
Even when the `n` is being multiplied by `4`. That contribution is irrelevant.
***
```
Algorithm Loop3(n):    cost  operations
   c = 1                 C1  n
   for i = 1 to n^2      C2  n^2
      c--                C3  n^2 - 1 
```

$$
\begin{align*}
T(n) &= C_1 \cdot n + C_2 \cdot n^2 + C_3 \cdot (n^2-1)\\
T(n) &= C_1 \cdot n + C_2 \cdot n^2 + C_3 \cdot n^2 - C_3\\
T(n) &= (C_2 + C_3) \cdot n^2 + C_1 \cdot n - C_3\\
T(n) &= n^2 + a\cdot n - b
\end{align*}
$$

After adding the costs, one can observe that `n^2` is the dominant term in the equation.
Thus, the algorithm has an `O(n^2)` order of growth. Quadratic.
***
```
Algorithm Loop4(n):    cost   operations
   d = 5                 C1   n
   for i = 1 to 3n       C2   3n
      for j = 1 to i     C3   SUM 3n - 1 
         d = d + j       C4   SUM 3n - 1 + n - 1
```
Until `for i = 1 to 3n`, the algorithm had a linear order of growth `O(n)`.
However, since there is a second loop inside for each `i`. Then, let's focus on the cost of that step using the formula for arithmetic series

$$
\begin{equation}
\sum_{i=1}^{k} i = \frac{k(k+1)}{2}
\end{equation}
$$

The cost of the inner loop is:

$$
\begin{align}
T(n) &= C_3 \left( \frac{3n (3n - 1)}{2} \right) \\
T(n) &= C_3 \cdot 3n^2 - \frac{C_3 \cdot 3n}{2}
\end{align}
$$

Where the dominant term is `3n^2`, thus the order of growth is `O(n^2)`.
***
```
Algorithm Loop5(n):     cost  operations
   e = 5                  C1  n
   for i = 1 to n^2       C2  n^2
      for j = 1 to i      C3  SUM n^2 - 1
         e = e + j        C4  1
```
Here, the inner loop carries the most cost. The arithmetic series is:

$$
\begin{equation}
\sum_{i=1}^{n^2} i = \frac{n^2(n^2+1)}{2}
\end{equation}
$$

Then the cost is:

$$
\begin{align}
T(n) &= C_3 \left( \frac{n^2 (n^2 - 1)}{2} \right) \\
T(n) &= C_3 \cdot n^4 - \frac{C_3 \cdot n^2}{2}
\end{align}
$$

Where the dominant term is `3n^4`, thus the order of growth is `O(n^4)`.

<br/>

## Analysis of a reversing algorithm
The following algorithm reverses a collection.  Answer the following:

- What is the basic operation for this algorithm?
- Describe the time complexity of this algorithm

```python
Reverse (A):
   # Input: an array A storing n elements.
   # Output: the same array with the elements in reversed order.
   for i = 1 to n-1
       x = A[i]
       for j = i down to 1
           A[j] = A[j-1]
       A[0] = x
```

Let us express this algorithm as a function T(n) where n is the size of the array
```
Algorithm T(n):     cost  time 
for i = 1 to n-1      C1  n-1
    x = i             C2  
    for j = i to 1    C3  SUM n-1
        j = j - 1     C4  1
    0 = x             C5  n-2
```

The basic operation if the swaping at C4, that happens insde the inner loop, until `j` reaches `1`.
Given that the inner loop runs `n-1` times, the series equations is:

$$
\begin{align*}
\sum_{i=1}^{n-1} i = \frac{n-1(n-1+1)}{2} \\
\sum_{i=1}^{n-1} i = \frac{(n-1)n}{2}
\end{align*}
$$

Expressing the cost as:

$$
\begin{align}
T(n) &= \frac{n^2 - n}{2}
\end{align}
$$

Where `n^2` is the dominant term, thus the algorithm has an order of growth of `O(n^2)`.
##
### Analysis of a reversing algorithm of O(n)

```
Given A the original non-mutable array, and R the reversed array
Algorithm T(n)           cost   times
tip = 0                   C1     1
end = n                   C2     1 
while tip < n / 2         C3     n/2
    R[tip] = A[end]       C4     n/2 - 1
    R[end] = A[tip]        .     .
    tip ++                 .     .
    end --                 .     .
return R                   C8    1
```
The basic operation here is assigning the tip of the reversed array to the end of the original array until the process reaches the middle.
Therefore, given the `while tip < n / 2`, if the operation that happens more times, having a cost of `C3 * n/2`.
The order of growth is `O(n)`, linear. 