// Given a non-empty array containing only positive integers, find if the array
// can be partitioned into two subsets such that the sum of elements in both
// subsets is equal.

// Note:
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
// Example 1:

// Input: [1, 5, 11, 5]

// Output: true

// Explanation: The array can be partitioned as [1, 5, 5] and [11].
// Example 2:

// Input: [1, 2, 3, 5]

// Output: false

// Explanation: The array cannot be partitioned into equal sum subsets.

// 2D dp
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;

        int target = sum / 2;

        // dp[i][j] == true means first i num can have a subarray sum to j
        vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1));

        for (auto &row : dp)
            row[0] = 1;

        for (int i = 1; i <= nums.size(); ++i)
            for (int j = 1; j <= target; ++j)
                dp[i][j] = dp[i - 1][j] ||
                           (j >= nums[i - 1] ? dp[i - 1][j - nums[i - 1]] : 0);

        return dp[nums.size()][target];
    }
};

// Optimized to 1D
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;

        int target = sum / 2;

        vector<bool> dp(target + 1);
        dp[0] = true;

        for (auto &&n : nums)
            for (int j = target; j > 0; --j)
                dp[j] = dp[j] || (j >= n ? dp[j - n] : false);
        // key point: j is start from right

        return dp[target];
    }
};

// backtracking
class Solution {
  public:
    bool canPartition(vector<int> &nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2)
            return false;

        sort(nums.begin(), nums.end(), greater<int>());

        auto backtrack = [&](auto &&self, int i, int target) {
            if (nums[i] > target)
                return false;

            if (nums[i] == target)
                return true;

            return self(self, i + 1, target - nums[i]) ||
                   self(self, i + 1, target);
        };

        return backtrack(backtrack, 0, sum / 2);
    }
};