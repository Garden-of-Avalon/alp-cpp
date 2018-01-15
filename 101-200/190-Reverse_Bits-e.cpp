// Reverse bits of a given 32 bits unsigned integer.

// For example, given input 43261596 (represented in binary as
// 00000010100101000001111010011100), return 964176192 (represented in binary as
// 00111001011110000010100101000000).

// Follow up:
// If this function is called many times, how would you optimize it?

// Related problem: Reverse Integer

// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;

        for (int i = 0; i < 32; ++i) {
            ret <<= 1;
            ret |= n & 1;
            n >>= 1;
        }

        return ret;
    }
};

// bitset is very special
// algorithm like reverse cannot be used
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> a(n), ret;

        for (int i = 0, j = 31; i < 32; ++i, --j)
            ret[i] = a[j];

        return ret.to_ulong();
    }
};

// TODO understand, pure bit manipulation
// https://leetcode.com/problems/reverse-bits/discuss/54741
class Solution {
  public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
// for 8 bit binary number abcdefgh, the process is as follow:
// abcdefgh -> efghabcd -> ghefcdab -> hgfedcba
