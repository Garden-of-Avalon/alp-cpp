// Say you have an array for which the ith element is the price of a given stock
// on day i.

// Design an algorithm to find the maximum profit. You may complete as many
// transactions as you like (ie, buy one and sell one share of the stock
// multiple times) with the following restrictions:

//     You may not engage in multiple transactions at the same time (ie, you
//     must sell the stock before you buy again). After you sell your stock, you
//     cannot buy stock on next day. (ie, cooldown 1 day)

// Example:

// prices = [1, 2, 3, 0, 2]
// maxProfit = 3
// transactions = [buy, sell, cooldown, buy, sell]

// correct thinking direction
// finite state machine
// ref:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)
// 3 states (indicate net money we have, start at 0):
// s0: can stay at s0, or buy and go to s1
// s1: can stay at s1, or sell and go to s2 (cooldown state, cannot buy)
// s2: cannot stay at s2, after 1 day cooldown, go to s1
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2)
            return 0;

        int n = prices.size();
        vector<int> s0(n), s1(n), s2(n);
        s0[0] = 0;
        s1[0] = -prices[0];
        s2[0] = INT_MIN; // impossible to sell at first day

        for (int i = 1; i < n; ++i) {
            s0[i] = max(s0[i - 1], s2[i - 1]);
            s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
            s2[i] = s1[i - 1] + prices[i];
        }

        return max(s0[n - 1], s2[n - 1]);
    }
};

// further optimized to O(1) space
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int s0 = 0, s1 = INT_MIN, s2 = 0;

        for (auto &&p : prices) {
            int pre_s2 = s2;
            s2 = s1 + p;
            s1 = max(s1, s0 - p);
            s0 = max(s0, pre_s2);
        }

        return max(s0, s2);
    }
};

// my own analysis, seems to be wrong way
// analysis
// vector input, return a int
// conditions
// => dp
// let dp[n] represents the max profit after the end of day n
// not day n price is price[n-1]
// if day n-1 must be selling transaction
// i.e. dp[n-1] != dp[n-2]
//     dp[n] = max(dp[n-1], dp[n-1]  + price[n-1] - price[n-2])
// if day n-1 can be a non-selling transaction
//     if day n-1 can be cooldown window
//     i.e. dp[n-1] == dp[n-2]
//         dp[n] = dp[n-1]
//     if day n-1 is not cooldown (n-2 is not selling)
//     i.e. dp[n-2] == dp[n-3]
//         dp[n] = dp[n-2] + max(0, price[n-1] - price[n-2])
// beginning cases:
// dp[0] = 0, dp[1] = 0, dp[2] = max(0, price[1] - price[0])
//
// code:
// int n = prices.size();
// vector<int> dp(n + 1); // all 0s
// dp[2] = max(0, prices[1] - prices[0]);
// for (int i = 3; i <= n; ++i) {
//     if (dp[i - 1] != dp[i - 2])
//         dp[i] = dp[i - 1] + max(0, prices[i - 1] - prices[i - 2]);
//     else {
//         // n-1 is cooldown
//         dp[i] = dp[i - 1];
//         if (dp[i - 2] == dp[i - 3])
//             dp[i] += max(0, prices[i - 1] - prices[i - 2]);
//     }
// }
// return dp[n];