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