// Reverse digits of an integer.
// Example1: x = 123, return 321
// Example2: x = -123, return -321
// Note:
// The input is assumed to be a 32-bit signed integer. Your function should
// return 0 when the reversed integer overflows.

class Solution {
  public:
    int reverse(int x) {
        int result = 0;
        while (x / 10) {
            (result *= 10) += (x % 10);
            x /= 10;
        }
        // last time, can cover x == 0 case
        // if overflow happen, it must be last operatrion
        // left part just check overflow
        return result == (result * 10 + x) / 10 ? result * 10 + x : 0;
    }
};