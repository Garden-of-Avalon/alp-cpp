// Calculate the sum of two integers a and b, but you are not allowed to use the
// operator + and -.
// Example:
// Given a = 1 and b = 2, return 3.
// Credits:
// Special thanks to @fujiaozhu for adding this problem and creating all test
// cases.

class Solution {
  public:
    int getSum(int a, int b) {
        int c = a ^ b;
        int carry = (a & b) << 1;
        return carry ? getSum(c, carry) : c;
    }
};