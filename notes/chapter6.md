# Dynamic Programming
## Basic Concepts
- Optimal solutions to problems and to count the number of solutions.
- Dynamic programming -> an algorithm that is almost like a brute force algorithm but it is also efficient.

### Finding an Optimal Solution
- Formulate the problem recursively so that the solution to the problem can be calculated from solutions to smaller subproblems

**Memorization**
- Store each function value in an array directly after calculating it. Then, when the value is needed again, it can be retrieved from the array without recursive calls.
- `ready[x]` indicates whether the value of `solve(x)` has been calculated, and if it is, `value[x]` contains this value.
```cpp
bool ready[N];
int value[N];
```
- The function handles the base cases. Then it checks from `ready[x]` if `solve(x)` has already been stored in `value[x]`, and if it is, the function directly returns it. Otherwise the function calculates the value of `solve(x)` recursively and stores it in `value[x]`.

**Iterative Implementation**
- Shorter and has smaller constant factors.
```cpp
// iterative implementation of minimum coin problem
value[0] = 0;
for (int x = 1; x <= n; x++) {
    value[x] = INF;
    for (auto c : coins) {
        if (x-c >= 0) {
            value[x] = min(value[x], value[x-c]+1);
        } 
    }
}
```

### Constructing a Solution
- Use another array `int first[N]` to store first value being used

### Counting Solutions
- Solve recursively
```cpp
// iterative implementation for counting solutions of coin problem
// count[x] equals the value of solve(x) for 0 ≤ x ≤ n:
count[0] = 1;
for (int x = 1; x <= n; x++) {
    for (auto c : coins) { 
        if (x-c >= 0) {
               count[x] += count[x-c];
               // if count >>>
               count[x] %= m    // m = 10^9 + 7
           }
    } 
}
```
<br>

## Further Examples
### Longest Increasing Subsequence
- The *longest increasing subsequence* in an array of `n` elements is a maximum length sequence of array elements that goes from left to right, and each element in the sequence is larger than the previous element.
- `length(k)` denotes the length of the longest increasing subsequence that ends at position `k`
  - Calculate all values of `length(k)` where `0 ≤ k ≤ n − 1`
- To calculate a value of `length(k)`, we should find a position `i < k` for which `array[i] < array[k]` and `length(i)` is as large as possible.
- $O(n^2)$ DP algorithm:
```cpp
for (int k = 0; k < n; k++) { 
    length[k] = 1;
    for (int i = 0; i < k; i++) { 
        if (array[i] < array[k]) {
            length[k] = max(length[k],length[i]+1);
        } 
    }
}
```

### Paths in a Grid
- Find a path from the upper-left corner to the lower-right corner of an `n × n` grid, with the restriction that we may only move down and right.
- Each square contains an integer, and the path should be constructed so that the sum of the values along the path is as large as possible.
- Formula: `sum(y, x) = max(sum(y, x − 1),sum(y − 1, x)) +value[y][x]`
- Since the function `sum` has two parameters, the dynamic programming `array` also has two dimensions.
- $O(n^2)$ DP algorithm:
```cpp
for (int y = 1; y <= n; y++) { 
    for (int x = 1; x <= n; x++) {
        sum[y][x] = max(sum[y][x-1],sum[y-1][x])+value[y][x];
    }
}
```

### Knapsack Problems
- `knapsack` refers to problems where a set of objects is given, and subsets with some properties have to be found.
- Ex: Given a list of weights `[w1,w2,...,wn]`, determine all sums that can be constructed using the weights.
  - Focus on subproblems where we only use the first `k` weights to construct sums.
- `possible(x,k) =true` if we can construct a sum `x` using the first `k` weights
- Formala: `possible(x,k) = possible(x − wk,k − 1) or possible(x,k − 1)`
  - based on the fact that we can either use or not use the weight $w_k$ in the sum
- $O(nm)$ (m is the total sum of weights) DP algorithm:
```cpp
// |= -> pipe operation (bitwise OR)
possible[0][0] = true;
for (int k = 1; k <= n; k++) {
    for (int x = 0; x <= m; x++) { 
        if (x-w[k] >= 0) {
            possible[x][k] |= possible[x-w[k]][k-1];
        }
        possible[x][k] |= possible[x][k-1];
    }
}
```
- More efficient way using only a one-dimensional array `possible[x]` that indicates whether we can construct a subset with sum x.
  - The trick is to update the array from right to left for each new weight:
```cpp
possible[0] = true;
for (int k = 1; k <= n; k++) {
    for (int x = m-w[k]; x >= 0; x--) { 
        possible[x+w[k]] |= possible[x];
    } 
}
```

### Permutations to Subsets
- Change an iteration over permutations into an iteration over subsets.
  - $2^n$ (subsets) <<< $n!$ (permutations)
- Example: Elevator with maximum weight `x` and `n` people who want to get from the ground floor to the top floor. Minimum number of rides needed to get everybody to the top floor?
- The idea is to calculate for each subset of people two values: the minimum number of rides needed and the minimum weight of people who ride in the last group.
- Let `rides(S)` denote the minimum number of rides for a subset S, and let `last(S)` denote the minimum weight of the last ride in a solution where the number of rides is minimum.

### Counting Tiles
- 