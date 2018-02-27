//  You are given coins of different denominations and a total amount of money.
//  Write a function to compute the number of combinations that make up that
//  amount. You may assume that you have infinite number of each kind of coin.

// Note: You can assume that

//     0 <= amount <= 5000
//     1 <= coin <= 5000
//     the number of coins is less than 500
//     the answer is guaranteed to fit into signed 32-bit integer

// Example 1:

// Input: amount = 5, coins = [1, 2, 5]
// Output: 4
// Explanation: there are four ways to make up the amount:
// 5=5
// 5=2+2+1
// 5=2+1+1+1
// 5=1+1+1+1+1

// Example 2:

// Input: amount = 3, coins = [2]
// Output: 0
// Explanation: the amount of 3 cannot be made up just with coins of 2.

// Example 3:

// Input: amount = 10, coins = [10]
// Output: 1

// dp
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        sort(coins.begin(), coins.end());
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1));

        for (int i = 0; i <= coins.size(); ++i)
            dp[i][0] = 1;

        for (int i = 1; i <= coins.size(); ++i)
            for (int j = 1; j <= amount; ++j)
                dp[i][j] = dp[i - 1][j] +
                           (j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0);

        return dp[coins.size()][amount];
    }
};

// optimized dp
// because dp[i][j] only relied on
// dp[i-1][j] (previous i's value) and dp[i][j - curr_coin]
// so it is independent from i
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        sort(coins.begin(), coins.end());

        vector<int> dp(amount + 1);

        dp[0] = 1;

        // after i_th loop
        // dp[j] means the ways to achieve target (j) use first i coins
        for (auto &&coin : coins)
            for (int j = coin; j <= amount; ++j)
                dp[j] += dp[j - coin];

        return dp[amount];
    }
};

// ref: 039
// TLE: we need less information
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        // if(!is_sorted(coins.begin(), coins.end()))
        sort(coins.begin(), coins.end());
        vector<vector<int>> combs;
        vector<int> curr;

        function<void(int, int)> backtrack = [&](int start, int target) {
            if (target == 0) {
                combs.push_back(curr);
                return;
            }
            for (int i = start; i < coins.size() && target >= coins[i]; ++i) {
                curr.push_back(coins[i]);
                backtrack(i, target - coins[i]);
                curr.pop_back();
            }
        };

        backtrack(0, amount);
        // for (auto &&v : combs) {
        //     for (auto &&x : v)
        //         cout << x << ' ';
        //     cout << '\n';
        // }

        return combs.size();
    }
};