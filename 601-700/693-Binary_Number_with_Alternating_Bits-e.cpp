// Given a positive integer, check whether it has alternating bits: namely, if
// two adjacent bits will always have different values.
// Example 1:
// Input: 5
// Output: True
// Explanation:
// The binary representation of 5 is: 101
// Example 2:
// Input: 7
// Output: False
// Explanation:
// The binary representation of 7 is: 111.
// Example 3:
// Input: 11
// Output: False
// Explanation:
// The binary representation of 11 is: 1011.
// Example 4:
// Input: 10
// Output: True
// Explanation:
// The binary representation of 10 is: 1010.

// bad solution
class Solution {
  public:
    bool hasAlternatingBits(int n) {
        int temp = 0xffffffff;
        int i = 0;
        while (n >> ++i)
            ;
        temp <<= i;

        return (temp ^ (n ^ n >> 1)) == 0xffffffff;
    }
};

// + and - have higher precedence than &

// good 1
bool hasAlternatingBits(int n) { return !((n ^= n >> 1) & n + 1); }

// good 2
bool hasAlternatingBits(int n) { return !((n ^= n >> 2) & n - 1); }

// other method 1
bool hasAlternatingBits(int n) {
    if (n == 0xaaaaaaaa)
        return true;
    bitset<32> b((n ^ n >> 1) + 1);
    return b.count() == 1;
}

// other method 2
bool hasAlternatingBits(int n) {
    bitset<32> b(n ^ n >> 2);
    return b.count() == 1;
}