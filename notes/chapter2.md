# Chapter 2
## C++
### I/O Operations
- Input and output efficiency (beginning)
```cpp
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
```
- `\n` is faster than `endl`
- `scanf` and `printf` from `C`
- To input an entire line
```cpp
string s;
getline(cin, s);
```
- File handling
```cpp
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
```

### Numbers
- Modular arithmetic
```
(a + b) mod m = (a mod m + b mod m) mod m 
(a − b) mod m = (a mod m − b mod m) mod m 
(a · b) mod m = (a mod m · b mod m) mod m
```
- To compare floating point numbers, two numbers are equal if the difference between them is less than `ε`, where `ε` is a small number.

### Shortening Code
- Type names: `typedef`
    - Short name to a data type, including complex types
- Macros: `#define`
    - macro specifies that certain strings in the code will be changed before the compilation.
    - macro can also have parameters to shorten loops and other structures.
<br>

## Recursion
- Permuations: `next_permutation(vector.begin(), vector.end())`

### Backtracking
- A backtracking algorithm begins with an empty solution and extends the solution step by step. 
- The search recursively goes through all different ways how a solution can be constructed.
- **Chessboard** problems
<br>

## Bit Manipulation
- Binary numbers
    - Signed and `unsigned`
    - Two's complement
    - Overflow

### Bit Operations
- AND (&), OR (|), NOT (~), XOR (^)
- Using the `AND` operation, we can check if a number `x` is even because `x & 1 = 0` if x is `even`, and `x & 1 = 1` if x is `odd`.More generally,x is divisible by 2k exactly when `x & (2k − 1) = 0`
- Bit shift
    - Left: x << k
    - Right: x >> k
- Bit mask
    - kth bit of a number is one exactly when `x & (1 << k)` is not zero.
    - `x |(1 << k)` sets the kth bit of x to one
    - `x & ~(1 << k)` sets the kth bit of x to zero
    - `x ˆ (1 << k)` inverts the kth bit of x
    - `x & (x − 1)` sets the last one bit of x to zero
    - `x & −x` sets all the one bits to zero, except for the last one bit.
    - `x | (x − 1)` inverts all the bits after the last one bit.
    - x is a power of two exactly when `x & (x − 1) = 0`
- Functions for counting bits

### Representing Sets
- Every subset of a set {0, 1, 2,..., n − 1} can be represented as an n bit integer whose one bits indicate which elements belong to the subset.
- Set Operations
    - Intersection -> &
    - Union -> |
    - Complement -> ~
    - Difference `(a\b)` -> `a & (~b)`
- Subset operations
- C++ `bitset`
    - array whose each value is either 0 or 1
    - bit operations can be directly used to manipulate bitsets
```cpp
bitset<10> s;
s[1] = 1;
s.count()
```