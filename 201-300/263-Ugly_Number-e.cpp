//  Write a program to check whether a given number is an ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 6, 8 are ugly while 14 is not ugly since it includes another
// prime factor 7.

// Note that 1 is typically treated as an ugly number.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

class Solution {
  public:
    bool isUgly(int num) {
        if (num <= 0)
            return false;

        for (auto &n : vector<int>({2, 3, 5}))
            while (num % n == 0)
                num /= n;

        return num == 1;
    }
};