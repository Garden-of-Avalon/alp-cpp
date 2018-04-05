//  You are given coins of different denominations and a total amount of money
//  amount. Write a function to compute the fewest number of coins that you need
//  to make up that amount. If that amount of money cannot be made up by any
//  combination of the coins, return -1.

// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)

// Example 2:
// coins = [2], amount = 3
// return -1.

// Note:
// You may assume that you have an infinite number of each kind of coin.

class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        // sort(coins.begin(), coins.end(), greater<int>());
        // sort(coins.begin(), coins.end());
        unordered_map<int, int> records; // target : res

        function<int(int)> helper = [&](int target) {
            if (target == 0)
                return 0;
            else if (target < 0)
                return INT_MAX;
            else {
                if (records.find(target) != records.end())
                    return records[target];

                int res = INT_MAX;
                for (int i = 0; i < coins.size(); ++i) {
                    int temp_tar = target - coins[i];
                    int curr = helper(temp_tar);
                    if (curr != INT_MAX)
                        res = min(curr + 1, res);
                }

                records.emplace(target, res);

                return res;
            }
        };

        int ret = helper(amount);

        return ret == INT_MAX ? -1 : ret;
    }
};

// DP
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i)
            for (auto &&c : coins)
                if (i - c >= 0 && dp[i - c] != -1)
                    dp[i] =
                        dp[i] > 0 ? min(dp[i], dp[i - c] + 1) : dp[i - c] + 1;

        return dp[amount];
    }
};

// TODO, think again
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        sort(coins.begin(), coins.end(), greater<int>());
        int res = amount + 1;

        function<void(int, int, int)> helper = [&](int st, int cnt,
                                                   int target) {
            // reduce calculations
            if (cnt + ceil(target * 1.0 / coins[st]) >= res)
                return;

            if (target == 0) {
                res = min(res, cnt);
                return;
            }

            for (int i = st; i < coins.size(); ++i)
                if (target >= coins[i])
                    helper(i, cnt + 1, target - coins[i]);
        };

        helper(0, 0, amount);

        return res > amount ? -1 : res;
    }
};