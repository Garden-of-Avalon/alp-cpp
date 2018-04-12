//  Write a program to find the n-th ugly number.

// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
// For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10
// ugly numbers.

// Note that 1 is typically treated as an ugly number, and n does not exceed
// 1690.

// TODO: think again
class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n);
        ugly[0] = 1;
        int p2 = 0, p3 = 0, p5 = 0;
        int t2, t3, t5; // times 2, times 3, times 5
        for (int i = 1; i < n; ++i) {
            t2 = ugly[p2] * 2, t3 = ugly[p3] * 3, t5 = ugly[p5] * 5;
            ugly[i] = min(t2, min(t3, t5));
            if (ugly[i] == t2)
                ++p2;
            if (ugly[i] == t3)
                ++p3;
            if (ugly[i] == t5)
                ++p5;
        }
        return ugly[n - 1];
    }
};