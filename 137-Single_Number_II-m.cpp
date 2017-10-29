// Given an array of integers, every element appears three times except for one,
// which appears exactly once. Find that single one.
// Note:
// Your algorithm should have a linear runtime complexity. Could you implement
// it without using extra memory?

// digital design, simplify truth table
// Use a and b to represent 3 states
// ab has 3 value, 00, 01, 10
// ab      c       ab
// 00      0       00
// 01      0       01
// 10      0       10
// 00      1       01
// 01      1       10
// 10      1       00
// 1st solution
// a = ~abc + a~b~c;
// b = ~a~bc + ~ab~c;
// 2nd way
// b = b~c~a + ~bc~a = (b xor c) ~a;
// a = ~a~newbc + a~newb~c = (a xor c) ~newb;
class Solution {
  public:
    int singleNumber(vector<int> &nums) {
        int a = 0, tempa;
        int b = 0;
        for (int &c : nums) {
            b = ~a & (b ^ c);
            a = ~b & (a ^ c);
        }
        // a is the one appear twice
        // b is the one appear exactly once
        return b;
    }
};