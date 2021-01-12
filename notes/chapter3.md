# Chapter 3
## Time Complexity
- Big O: Worst case situation
- Calculation:
    - Single commands: O(1)
    - Loops: O(n)
    - Code blocks add up
    - Nested blocks multiply
- If an algorithm consists of consecutive phases, the total time complexity is the largest time complexity of a single phase.
- The time complexity of a **recursive function** depends on the number of times the function is called and the time complexity of a single call. The total time complexity is the product of these values.

### Common Time Complexities
- O(1)
- O(log n)
- O($\sqrt{n}$)
- O(n)
- O(n log n): Sorting or accessing data structures
- O($n^2$): pairs of elements
- O($n^3$): triplets of elements
- O($2^n$): subsets
- O(n!): permutations
- Polynomial and NP-hard problems

### Time Complexity from Input Size
| Input size | Expected time complexity |
| :--------- | ------------------------:|
| n <= 10 | O(n!) |
| n <= 20 | O($2^n$) |
| n <= 500 | O($n^3) |
| n <= 5000 | O($n^2) |
| n <= $10^6$ | O(n log n) or O(n) |
| large n | O(n) or O(1) |

### Formal Definitions
- O notation gives an *upper bound* for the running time of the algorithm for sufficiently large inputs.
- $\Omega$ notation gives a lower bound for the running time of an algorithm.
- $\Theta$ notation gives an exact bound
  - The time complexity of an algorithm is $\Theta(f(n))$ if it is both O(f(n)) and $\Omega(f(n))$.
<br>

## Algorithm Design
### Maximum Subarray Sum
- O($n^3$): Three nested loops, checking all possible subarrays
- O($n^2$): Two nested loops, sum while moving the end of the subarray
- O(n):
  - Calculate for each array position the maximum sum of a subarray that ends at that position.
  - Answer = maximum of those sums
```cpp
int best = 0, sum = 0;
for (int k = 0; k < n; k++) {
    sum = max(array[k], sum + array[k]);
    best = max(best, sum);
}
cout << best << "\n";
```

### Two Queens Problem
- Efficient algorithm: calculate the number of squares that a single queen attacks
- A queen attacks n − 1 squares horizontally and n − 1 squares vertically. Then, for both diagonals, it attacks d − 1 squares where d is the number of squares on the diagonal.
- So, O(1) time to calculate squares for second queen
- Thus, complexity = O($n^2$)
- Alternatively, formulate a **recursive function** that counts the number of combinations.
- O(n) solution: recursive formula
- O(1) solution: closed-form formula
<br>

## Code Optimization
- `break` whenever possible

### Compiler Output
- Compiler _optimizes_ code
- `-S` flag to get compiler output in `Assembly`
- [Compiler Explorer](https://godbolt.org)
- Compiler Optimizations
- Hardware-specific Optimizations
  - `-march=native` flag (g++) for optimizations
  - `#pragma GCC target ("arch=<architecture>")`: code to specify architecture for optimizations

### Processor Features
- Caches
  - Outermost loop should handle the first dimension, and the innermost
loop should handle the second dimension.
- Parallelism
  - Two consecutive instructions can be executed in parallel if they do not depend on each other.
  - Example: Use two variables for independent operations in loops instead of one, so that code is run parallelly and thus, faster.