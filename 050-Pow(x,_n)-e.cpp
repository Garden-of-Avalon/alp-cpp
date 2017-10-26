// Implement pow(x, n).

class Solution {
  public:
    double myPow(double x, int n) {
        if (!n)
            return 1;
        if (n < 0) {
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