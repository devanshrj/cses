# Data Structures
- [Cheatsheet](https://www.bigocheatsheet.com)
## Dynamic Arrays
- Fixed array: `type array[n]`;

### Vectors
- Dynamic array to efficiently add and remove elements at the end of the structure.
- Elements can be accessed like in an ordinary array.
- `push_back` and `pop_back` operations: O(1)
```cpp
// creating vector
vector<int> v;
v.push_back(1);

// vector initialisation
vector<int> v = { 1, 2, 3 };

// access elements
v[0] = 2;

// vector with num of elements and initial values
vector<int> v(5, 1);    // 5 elements, initialised to 1

// size of vector
v.size();

// vector traversal
for (auto i : v)
    cout << i << endl;

// return last element
v.back();

// remove last element
v.pop_back();
```

### Iterators and Ranges
- An *iterator* is a variable that points to an element of a data structure.
  - `begin()`: first element in structure
  - `end()`: position after last element
- A *range* is a sequence of consecutive elements in a data structure.
  - Iterators `begin()` and `end()` define a range that contains all elements in a data structure.
- STL functions
```cpp
sort(v.begin(), v.end());
reverse(v.begin(), v.end());
random_shuffle(v.begin(), v.end());
```
- The element to which an iterator points can be accessed using the **\* syntax**.
```cpp
// access first element
cout << *v.begin();
```
- Bounds: functions use binary search so O(log n)
  - `lower_bound` gives an iterator to the first element in a sorted range whose value is *at least x*
  - `upper_bound` gives an iterator to the first element whose value is *larger than x*
  - If there is no such element, the functions return an iterator to the element after the last element in the range.
```cpp
auto a = lower_bound(v.begin(), v.end(), elem);
if (a != v.end())
    // lower bound exists
    cout << "Lower bound: " << *a << '\n';
auto b = upper_bound(v.begin(), v.end(), elem);
```

### Other Structures
**Deque**
- Dynamic array that can be efficiently manipulated at both ends of the structure.
  - Operations: `push_back`, `pop_back`, `push_front`, `pop_front`
  - O(1) on average
- Use only if there is a need to manipulate both ends of an array
  
**Stack (LIFO)**
- Based on deque
- Operations
  - `push` and `pop` to insert and remove elements at the end of the structure
  - `top` retrieves the last element

**Queue (FIFO)**
- Elements are inserted at the end of the structure and removed from the front of the structure. 
- Both the functions `front` and `back` are provided for accessing the first and last element.
```cpp
deque<int> d;
stack<int> s;
queue<int> q;
```
<br>

## Set Structures
- Sets are implemented so that the below operations are efficient
  - Operations: insertion, search, removal
- Sets store elements in a sorted manner

### Sets and Multisets
- Sets:
  - `set` is based on a **balanced binary search tree** and its operations work in O(log n) time.
  - `unordered_set` is based on a **hash table** and its operations work in O(1) time.
- Operations:
  - `insert` adds an element to the set
  - `count` returns the number of occurrences of an element in the set
  - `erase` removes an element from the set.
- All elements in a set are *distinct*, so no duplicate elements.
  - `count` always return either 0 or 1
- `find(x)` returns an iterator that points to an element whose value is x
  - iterator is `end()` if x is not in set
- `lower_bound(x)` and `upper_bound(x)` return an iterator to the smallest element in a set whose value is *at least* or *larger than* x
  - if element doesn't exist, return `end()`
- \[ ] notation is not applicable.
```cpp
set<int> s;
s.insert(1);
s.insert(2); // [1, 2]
s.count(1); // 1
s.erase(2); // [1]

// traversal
for (auto i : s)
    cout << i << '\n';

// find x
auto it = s.find(x);

// lower bound
cout << *s.lower_bound(x) << "\n";
```

**Multisets**
- Set that can have several copies of the same value.
  - `multiset` and `unordered_multiset`
- *Not efficient* to count the number of occurences of a value in a multiset using the `count` function.
```cpp
// remove all occurences of x
multiset<int> s;
s.erase(x);

// remove only one occurence of x
s.erase(s.find(x));
```

### Maps
- A map is a set that consists of key-value pairs.
    - `map` is based on a **balanced binary search tree** and accessing elements takes O(log n) time
    - `unordered_map` uses **hashing** and accessing elements take O(1) time
- If the value of a key is requested but the map does not contain it, the key is automatically added to the map with a default value.
- `count` checks if a key exists in a map.
```cpp
// declaration
map<key_type, value_type> m;

// inserting key-value pairs
m[key] = value;

// check if a key exists
if (m.count(key))
    // key exists

// traversal
// first -> key, second -> value
for (auto i : m)
    cout << i.first << ' ' << i.second << '\n';
```

### Priority Queues
- Multiset that supports element insertion and, depending on the type of the queue, retrieval and removal of either the minimum or maximum element.
- Insertion and removal take O(log n) time, and retrieval takes O(1) time.
- Based on **heap structure** (special binary structure)
- If we only need to efficiently find minimum or maximum elements, use a priority queue instead of a set or multiset.
- Default: elements are sorted in decreasing order
```cpp
priority_queue<int> q;
q.push(3);
q.push(5);
cout << q.top() << '\n';    // 5
q.pop();
cout << q.top() << '\n';    // 3

// priority queue to find and remove smallest element
priority_queue<int, vector<int>, greater<int>> q;
```

### Policy-Based Sets
- Data structures that are not part of STL are called *policy-based* structures.
```cpp
// for policy-based structures
#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds;
```
- Example: `indexed_set` that is like `set` but can be indexed like an array.
```cpp
// indexed_set for int
typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;
```
<br>

## Experiments
### Set vs Sorting
- Both the `set` algorithm and the `sorting` algorithm work in O(n log n) time; still the latter is much faster.
- Reason: Sorting is a simple operation, while the balanced binary search tree used in `set` is a complex data structure.
- Time: sorting > unordered_set > set

### Map vs Array
- Maps have large constant factors
- Arrays should be used whenever possible instead of maps. 
- `unordered_map` provides O(1) time operations but there are large constant factors hidden in the data structure.

### Priority Queue vs Multiset
- Priority queue is faster than multiset