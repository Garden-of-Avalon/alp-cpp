// You are climbing a stair case. It takes n steps to reach to the top.
// Each time you can either climb 1 or 2 steps. In how many distinct ways can
// you climb to the top?
// Note: Given n will be a positive integer.

class Solution {
  public:
    int climbStairs(int n) {
        if (n < 3)
            return n;
        // ways last setp is one step; ... two step
        int endOne = 1, endTwo = 1;
        int result;
        // 3 to n
        for (int i = 2; i < n; ++i) {
            result = endOne * 2 + endTwo;
            // if we use endTwo = endOne, information of endTwo will lose
            swap(endOne, endTwo);
            endOne = endOne + endTwo;
        }
        return result;
    }
};