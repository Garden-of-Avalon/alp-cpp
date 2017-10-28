// Write an algorithm to determine if a number is "happy".
// A happy number is a number defined by the following process: Starting with
// any positive integer, replace the number by the sum of the squares of its
// digits, and repeat the process until the number equals 1 (where it will
// stay), or it loops endlessly in a cycle which does not include 1. Those
// numbers for which this process ends in 1 are happy numbers.
// Example: 19 is a happy number
//     1^2 + 9^2 = 82
//     8^2 + 2^2 = 68
//     6^2 + 8^2 = 100
//     1^2 + 0^2 + 0^2 = 1
// Credits:
// Special thanks to @mithmatt and @ts for adding this problem and creating all
// test cases.

class Solution {
    int squareSum(int n) {
        int sum = 0, temp;
        while (n) {
            temp = n % 10;
            sum += temp * temp;
            n /= 10;
        }
        return sum;
    }

  public:
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = squareSum(slow);
            fast = squareSum(squareSum(fast));
        } while (slow != fast);
        // slow and fast will finally meet
        return slow == 1;
    }
};