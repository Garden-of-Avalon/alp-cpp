// Given an integer (signed 32 bits), write a function to check whether it is a
// power of 4.
// Example:
// Given num = 16, return true. Given num = 5, return false.
// Follow up: Could you solve it without loops/recursion?
// Credits:
// Special thanks to @yukuairoy for adding this problem and creating all test
// cases.

class Solution {
  public:
    bool isPowerOfFour(int num) {
        // 0xA = 1010
        return num > 0 && !(num & (num - 1)) && num & 0x55555555;
    }
};

class Solution {
  public:
    bool isPowerOfFour(int num) {
        // 0xA = 1010
        return num > 0 && !(num & (num - 1)) && !(num % 3);
    }
};