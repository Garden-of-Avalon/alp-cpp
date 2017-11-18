// Find the largest palindrome made from the product of two n-digit numbers.
// Since the result could be very large, you should return the largest
// palindrome mod 1337.
// Example:
// Input: 2
// Output: 987
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
// Note:
// The range of n is [1,8].

//  1:       `  3 x          3 =                    9
//  2:         99 x         91 =                 9009
//  3:        913 x        993 =               906609
//  4:       9999 x       9901 =             99000099
//  5:      99979 x      99681 =           9966006699
//  6:     999999 x     999001 =         999000000999
//  7:    9997647 x    9998017 =       99956644665999
//  8:   99999999 x   99990001 =     9999000000009999
//  9:  999920317 x  999980347 =   999900665566009999
// 10: 9999999999 x 9999900001 = 99999000000000099999

class Solution {
    // long buildpl(const int &half) {
    //     string halfstr = to_string(half);
    //     string rightstr(halfstr.rbegin(), halfstr.rend());
    //     return stol(halfstr + rightstr);
    // }

    long buildpl(int half) {
        long pl = half;
        while (half) {
            pl = pl * 10 + half % 10;
            half /= 10;
        }
        return pl;
    }

  public:
    int largestPalindrome(int n) {
        if (n == 1)
            return 9;

        int x = pow(10, n) - 1, y;

        if (!(n % 2)) {
            y = x - pow(10, n / 2) + 2;
            return static_cast<long>(x) * y % 1337;
        }

        int low = pow(10, n - 1);
        for (int half = x - 1; half > low; --half) {
            long pl = buildpl(half);
            int sqrtpl = sqrt(pl);
            for (y = x; y >= sqrtpl; --y)
                if (!(pl % y))
                    return pl % 1337;
        }

        return 0;
    }
};