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
  public:
    int largestPalindrome(int n) {
        long x = pow(10, n + 1) - 1, y;
        if (!n % 2) {
            y = x - pow(10, n / 2 + 1) + 2;
            return x * y % 1337;
        }
    }
};