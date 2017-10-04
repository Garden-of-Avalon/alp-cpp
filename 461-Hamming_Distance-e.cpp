// The Hamming distance between two integers is the number of positions at which
// the corresponding bits are different.
// Given two integers x and y, calculate the Hamming distance.
// Note:
// 0 ≤ x, y < 231.
// Example:
// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are
// different.

class Solution {
  public:
    int hammingDistance(int x, int y) {
        // xor
        x = x ^ y;
        // count 1s
        // 0x55555555 = 0101 0101 0101 0101 0101 0101 0101 0101
        x = x - ((x >> 1) & 0x55555555);
        // 0x33333333 = 0011 0011 0011 0011 0011 0011 0011 0011
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        // 0x0F0F0F0F = 0000 1111 0000 1111 0000 1111 0000 1111
        x = (x + (x >> 4)) & 0x0F0F0F0F;
        x = x + (x >> 8);
        x = x + (x >> 16);
        // 0x0000003F = 0000 0000 0000 0000 0000 0000 0011 1111
        return x & 0x0000003F;
    }
};