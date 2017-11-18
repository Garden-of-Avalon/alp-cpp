// Given an integer n, return the number of trailing zeroes in n!.
// Note: Your solution should be in logarithmic time complexity.
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

class Solution {
  public:
    int trailingZeroes(int n) {
        int temp, zeros = 0;
        while (n) {
            temp = n / 5;
            zeros += temp;
            n = temp;
        }
        return zeros;
    }
};

// ever 5 contributes an zero
// 5, 10, 15 ...
// 25 = 5 * 5 contributes an extra one
// 125 = 5 * 5 * 5 contributes 3 in total