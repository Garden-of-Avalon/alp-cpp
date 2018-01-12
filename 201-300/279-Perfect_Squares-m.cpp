//  Given a positive integer n, find the least number of perfect square numbers
//  (for example, 1, 4, 9, 16, ...) which sum to n.

// For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13,
// return 2 because 13 = 4 + 9.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

class Solution {
  public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        // for(int i = 1; i <= n; ++i)
        //     for(int j = 1, j_squ; (j_squ = j * j) <= i; ++j)
        for (int j = 1, j_squ; (j_squ = j * j) <= n; ++j)
            for (int i = j_squ; i <= n; ++i)
                dp[i] = min(dp[i], dp[i - j_squ] + 1);

        return dp[n];
    }
};

// mathematical way
// https://www.alpertron.com.ar/4SQUARES.HTM
class Solution {
  public:
    int is_square(int n) {
        int t = sqrt(n);
        return t * t == n;
    }
    int numSquares(int n) {
        // case 1
        if (is_square(n))
            return 1;

        // case 4: 4^r(8k + 7)
        while (n % 4 == 0)
            n /= 4;
        if (n % 8 == 7)
            return 4;

        // case 2
        for (int i = 1, i_squ; (i_squ = i * i) <= n; ++i)
            if (is_square(n - i_squ))
                return 2;

        // case 3
        return 3;
    }
};