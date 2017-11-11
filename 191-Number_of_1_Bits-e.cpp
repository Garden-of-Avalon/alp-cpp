// Write a function that takes an unsigned integer and returns the number of ’1'
// bits it has (also known as the Hamming weight).
// For example, the 32-bit integer ’11' has binary representation
// 00000000000000000000000000001011, so the function should return 3.
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// Ref. 461 Hamming Distance
class Solution {
  public:
    int hammingWeight(uint32_t n) {
        // 0x55555555 = 0101 0101 0101 0101 0101 0101 0101 0101
        n = n - ((n >> 1) & 0x55555555);
        // 0x33333333 = 0011 0011 0011 0011 0011 0011 0011 0011
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        // 0x0F0F0F0F = 0000 1111 0000 1111 0000 1111 0000 1111
        n = (n + (n >> 4)) & 0x0F0F0F0F;
        n = n + (n >> 8);
        n = n + (n >> 16);
        // 0x0000003F = 0000 0000 0000 0000 0000 0000 0011 1111
        return n & 0x0000003F;
    }
};

// C++11 way
class Solution {
  public:
    int hammingWeight(uint32_t n) { return bitset<32>(n).count(); }
};
