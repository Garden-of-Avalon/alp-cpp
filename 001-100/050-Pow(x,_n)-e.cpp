// Implement pow(x, n), which calculates x raised to the power n (x^n).

// Example 1:

// Input: 2.00000, 10
// Output: 1024.00000
// Example 2:

// Input: 2.10000, 3
// Output: 9.26100
// Example 3:

// Input: 2.00000, -2
// Output: 0.25000
// Explanation: 2-2 = 1/22 = 1/4 = 0.25
// Note:

// -100.0 < x < 100.0
// n is a 32-bit signed integer, within the range [−2^31, 2^31 − 1]

// better handling INT_MIN
class Solution {
  public:
    double myPow(double x, int n) {
        if (!n)
            return 1;

        int next_n = n / 2;
        if (n < 0) {
            next_n = -next_n;
            x = 1 / x;
        }

        return n % 2 ? x * myPow(x * x, next_n) : myPow(x * x, next_n);
    }
};

class Solution {
  public:
    double myPow(double x, int n) {
        if (!n)
            return 1;
        if (n < 0) {
            if (n == INT_MIN)
                n += 2;
            n = -n;
            x = 1 / x;
        }
        return n % 2 ? x * myPow(x * x, n / 2) : myPow(x * x, n / 2);
    }
};

// TLE
// class Solution {
//   public:
//     double myPow(double x, int n) {
//         if (!n)
//             return 1;
//         int absn = n ? n : -n;
//         int tempx = x;
//         for (int i = 0; i < absn; ++i)
//             x *= tempx;

//         return n ? x : 1 / x;
//     }
// };