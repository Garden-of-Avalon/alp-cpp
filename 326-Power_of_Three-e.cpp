// Given an integer, write a function to determine if it is a power of three.
// Follow up:
// Could you do it without using any loop / recursion?
// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test
// cases.

class Solution {
  public:
    // use log or log2 may lead to wrong answer due to accuracy
    bool isPowerOfThree(int n) {
        return n > 0 && fmod(log10(n) / log10(3), 1) == 0;
    }
};

class Solution {
  public:
    // 3^19
    bool IsPowerOfThree(int n) { return n > 0 && (1162261467 % n == 0); }
}