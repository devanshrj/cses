# Sorting and Searching
## Sorting Algorithms
- Sort an array of n elements in increasing order

### Bubble Sort
- O($n^2$)
- If two consecutive elements are in wrong order, swap them.
- After k rounds, the k largest elements will be in the correct positions.
```cpp
for (int i = 0; i < n; i++) {
    for (int j = 0; j < n-1; j++) {
        if (array[j] > array[j+1]) { 
            swap(array[j],array[j+1]);
        } 
    }
}
```
- Swapping algorithms are atleast O($n^2$)

**Inversions**
- Inversion: a pair of array indices (a, b) such that `a < b` and `array[a] > array[b]`
- Sorted array => no inversions

### Merge Sort
- O(n log n)
- Recursive algorithm to reorder elements using divide and conquer
- O(log n) recursive levels, and processing each level takes a total of O(n) time
- Steps to sort `array[a...b]`:
  1. If a = b, array is sorted.
  2. Calculate the position of the middle element: `k = ⌊(a + b)/2⌋`.
  3. Recursively sort the subarray `array[a...k]`.
  4. Recursively sort the subarray `array[k+1...b]`.
  5. Merge the sorted subarrays `array[a...k]` and `array[k+1...b]` into a sorted subarray `array[a . . . b]`.

### Lower Bound for Sorting
- Worst case number of steps in a sorting algorithm that uses comparisons are $\Omega(n log n)$

### Counting Sort
- Sorts an array in O(n) time assuming that every element in the array is an integer between 0...c and c = O(n).
- Steps:
  - Create a bookkeeping array, whose indices are elements of the original array. 
  - Iterate through the original array and calculate how many times each element appears in the array.
- Construction of bookkeeping array takes O(n) time. After this, the sorted array can be created in O(n) time using the bookkeeping array.

### Sorting in Practice
- C++: `sort` 
  - O(n log n)
```cpp
vector<int> v;
string v;

// increasing order
sort(v.begin(), v.end());

// decreasing order
sort(v.rbegin(), v.rend());

// array
int a[n];
sort(a, a + n);
```

**Comparison Operators**
- `sort` function requires that a *comparison operator* is defined for the data type of the elements to be sorted. 
- When sorting, this operator will be used whenever it is necessary to find out the order of two elements.
- Pairs are sorted primarily according to their first elements and secondarily according to their second elements
- Similar for tuples^

**User-defined Structs**
- User-defined structs do not have a comparison operator automatically. 
- The operator should be defined inside the struct as a function `operator<`, whose parameter is another element of the same type. 
- The operator should return `true` if the element is smaller than the parameter, and `false` otherwise.

**Comparison Functions**
- External *comparison function* to the `sort` function as a callback function.
```cpp
// comparison function (T is any type)
bool comp(T a, T b)

// sorting use comp
sort(v.begin(), v.end(), comp);
```
<br>

## Solving Problems by Sorting
- Applications: check if all elements in an array are unique, count the number of distinct elements, find the most frequent element, and find two elements whose difference is minimum

### Sweep Line Algorithms
- Sweep line algorithm models a problem as a set of events that are processed in a sorted order.
- Example: Maximum number of customers who visited a restaurant at the same time, given arriving and leaving times.
- Approach:
  - Two events for each customer: arrival and leaving.
  - Sort the events and go through them according to their times. 
  - Maintain a counter: value increases when a customer arrives and decreases when a customer leaves. 
  - Answer: largest value of the counter.

### Scheduling Events
- Sort the input data and use greedy approach
- A **greedy algorithm** always makes a choice that looks the best at the moment and never takes back its choices.
- Example: Given n events with their starting and ending times, find a schedule that includes as many events as possible.
- Approach (greedy)):
  - Sort the events according to their ending times
  - Always select the next possible event that ends as early as possible.

### Tasks and Deadlines
- Given n tasks with durations and deadlines, task is to choose an order to perform the tasks.
- For each task, earn `d − x` points where d is the task’s deadline and x is the moment when we finish the task.
- Greedy strategy: perform the tasks sorted by their durations in increasing order.
<br>

## Binary Search
- O(log n)
- Search an element in a sorted array

### Implementation
- First method: algorithm halves the size of the subarray at each step
```cpp
int a = 0, b = n - 1; 
while (a <= b) {
    int k = (a + b) / 2;
    if (array[k] == x) {
       // x found at index k
    }
    if (array[k] < x) a = k + 1;
    else b = k - 1; 
}
```
- Second method: go through the array from left to right making jumps. halving jump length on each round

### Finding Optimal Solutions
- `valid(x)` returns `true` if x is a valid solution and `false` otherwise. 
- `valid(x)` is `false` when x < k and `true` when x ≥ k. 
- Use binary search to efficiently find the value of k.
  - Find largest value of x for which `valid(x)` is `false`. Thus, the next value k = x + 1 is the smallest possible value for which `valid(k)` is `true`.
- Implementation:
```cpp
int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (!valid(x + b)) 
        x += b; 
}
int k = x + 1;
```
- Initial jump length z is upper bound, i.e., `valid(z)` is `true`
- Algorithm calls the function `valid` O(log z) times, so the running time depends on the function `valid`.