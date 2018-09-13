# C++ core usages

## Basic grammar

C style grammar. Skipped here.

## Containers library

### vector

```cpp
#include <vector>

using std::vector;

vector<int> v1; // v1.size() == 0
vector<int> v2(10); // 10 0s
vector<int> v3(10, 1); // 10 1s
vector<int> v4 = {1, 2, 3, 4};

int e = v2[0]; // initial e with the value of first element in v2
auto it = v3.begin(); // type of 'it' is vector<int>::iterator
```

### unordered_map

```cpp
#include <unordered_map>

using std::unordered_map;


```

### unordered_set


### map


### set


### queue and deque


### priority queue


### list

## Strings library

### Null-terminated byte strings, cctype

isalpha, islower, isupper, isdigit, isspace, ispunct

tolower, toupper

atoi, atol, atoll, converts a byte string to an integer value 

### string (basic_string<char>)

at, front, back, c_str

clear, insert, erase, push_back, pop_back, append, +=, replace

substr, copy, resize

stoi, stol, stoll, stof/d, stold, to_string

find rfind

find_first_of find_first_not_of

find_last_of find_last_not_of

## Algorithms library

copy, remove, erase?,

find, lower_bound, upper_bound,

inplace_merge 

transform

## Numerics library

### cmath

abs, labs, llabs, fabs

fmod, fmax, fmin

exp, exp2, log, log10, log2

pow, sqrt

ceil, floor, round, lround, llround

### numeric

gcd/lcm (C++17)

iota

accumulate

## Iterator library

advance, distance, prev, next

## Utilities library

swap, exchange

pair

bitset

smart pointer, allocator, malloc

date and time

### random