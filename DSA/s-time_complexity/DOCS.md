### Order of growth

- Logarithmic = log<sub>2</sub>(n)
- Linear = n
- Linearithmic = n log n
- Quadratic = n<sup>2</sup>
- Cubic = n<sup>3</sup>
- Exponential = 2<sup>n</sup>
- Factorial = n!

| Size / complexity |     log n     |       n       |    n log n    |  n<sup>2</sup>   |  n<sup>3</sup>   |   2<sup>n</sup>  |      n!          |
|-------------------|---------------|---------------|---------------|------------------|------------------|------------------|------------------|
| 1                 |               |               |               |                  |                  |                  |                  |
| 10                |               |               |               |                  |                  |                  |                  |
| 100               |               |               |               |                  |                  |                  |                  |
| 1000              | 9.966         | 1000          | 9966          | 1e6              | 1e9              | 1e301            | 4e2567           |
| 10000             |               |               |               |                  |                  |                  |                  |
| 100000            |               |               |               |                  |                  |                  |                  |
| 1000000           |               |               |               |                  |                  |                  |                  |

Computed value using [Wolfram Alpha](https://www.wolframalpha.com).

### Size of n that can be solve on a given time 

| T(n)          | 1 second | 1 minute |  1 hour  |  1 day   |  1 year  |
| --------------|----------|----------|----------|----------|----------|
| log n         |          |          | &#x221e; |          |          |
| n             |          |          | 3.6e12   |          |          |
| n log n       |          |          | 9.8e10   |          |          |
| n<sup>2</sup> |          |          | 1.8e6    |          |          |
| n<sup>3</sup> |          |          | 15326    |          |          |
| 2<sup>n</sup> |          |          | 41       |          |          |
| n!            |          |          | 15       |          |          |