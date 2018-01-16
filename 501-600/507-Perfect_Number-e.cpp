// We define the Perfect Number is a positive integer that is equal to the sum
// of all its positive divisors except itself. Now, given an integer n, write a
// function that returns true when it is a perfect number and false when it is
// not.

// Example:

// Input: 28
// Output: True
// Explanation: 28 = 1 + 2 + 4 + 7 + 14

// Note: The input number n will not exceed 100,000,000. (1e8)

class Solution {
  public:
    bool checkPerfectNumber(int num) {
        if (num <= 0)
            return false;

        int sqr = sqrt(num);
        int sum = 1;
        for (int i = 2; i <= sqr; ++i)
            if (num % i == 0) {
                sum += i + num / i;
            }

        if (sqr * sqr == num)
            sum -= sqr;

        return sum == num;
    }
};

// WTF
class Solution {
public:
    bool checkPerfectNumber(int num) {
        static unordered_set<int> n = {6, 28, 496, 8128, 33550336};
        return n.find(num) != n.end();
    }
};