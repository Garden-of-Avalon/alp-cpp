// X is a good number if after rotating each digit individually by 180 degrees,
// we get a valid number that is different from X.  Each digit must be rotated -
// we cannot choose to leave it alone.

// A number is valid if each digit remains a digit after rotation. 0, 1, and 8
// rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each
// other, and the rest of the numbers do not rotate to any other number and
// become invalid.

// Now given a positive number N, how many numbers X from 1 to N are good?

// Example:
// Input: 10
// Output: 4
// Explanation:
// There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
// Note that 1 and 10 are not good numbers, since they remain unchanged after
// rotating. Note:

// N  will be in range [1, 10000].

// DP: TODO

// 5 ms
class Solution {
    bool check(int n) {
        int cnt = 0; // cnt of 2569;
        while (n > 0) {
            int digit = n % 10;
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9)
                ++cnt;
            else if (digit == 3 || digit == 4 || digit == 7)
                return false;
            n /= 10;
        }
        return cnt;
    }

  public:
    int rotatedDigits(int N) {
        int ret = 0;
        for (int i = 2; i <= N; ++i)
            ret += check(i);
        return ret;
    }
};

// 19 ms
class Solution {
    bool check(const int &n) {
        string nstr = to_string(n);
        int cnt = 0; // cnt of 2569;
        for (auto &&c : nstr)
            if (c == '2' || c == '5' || c == '6' || c == '9')
                ++cnt;
            else if (c == '3' || c == '4' || c == '7')
                return false;
        return cnt;
    }

  public:
    int rotatedDigits(int N) {
        int ret = 0;
        for (int i = 2; i <= N; ++i)
            ret += check(i);
        return ret;
    }
};