// Given a positive integer num, write a function which returns True if num is a
// perfect square else False.

// Note: Do not use any built-in library function such as sqrt.

// Example 1:

// Input: 16
// Returns: True
// Example 2:

// Input: 14
// Returns: False

// Credits:
// Special thanks to @elmirap for adding this problem and creating all test
// cases.

class Solution {
    int mysqrt(int n) {
        long long r = n;
        while (r * r > n)
            r = (r + n / r) / 2;
        return r;
    }

  public:
    bool isPerfectSquare(int num) {
        int sqroot = mysqrt(num);
        return sqroot * sqroot == num;
    }
};

// BS
class Solution {
  public:
    bool isPerfectSquare(int n) {
        int l = 1, r = n;

        while (l <= r) {
            long long mid = l + (r - l) / 2;
            auto square = mid * mid;
            if (square == n)
                return true;
            else if (square > n)
                r = mid - 1;
            else
                l = mid + 1;
        }
        // now r is the (int)sqrt, but r * r must < num
        return false;
    }
};