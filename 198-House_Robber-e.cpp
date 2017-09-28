// You are a professional robber planning to rob houses along a street. Each
// house has a certain amount of money stashed, the only constraint stopping you
// from robbing each of them is that adjacent houses have security system
// connected and it will automatically contact the police if two adjacent houses
// were broken into on the same night.
// Given a list of non-negative integers representing the amount of money of
// each house, determine the maximum amount of money you can rob tonight without
// alerting the police.
// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test
// cases. Also thanks to @ts for adding additional test cases.

class Solution {
  public:
    int rob(vector<int> &nums) {
        int result = 0, resultprev = 0;
        for (auto &n : nums) {
            swap(result, resultprev);
            // actually max(n + resultprev, result)
            result = max(n + result, resultprev);
        }
        return result;
    }
};

// The following answer's time limit exceed due to recalculations of subarrays
// Similar to analysis of f(n) = f(n-1) + f(n-2)

// class Solution {
//     int robhelper(vector<int> &nums, int start, int end) {
//         if (start == end)
//             return nums[start];
//         if (start < end)
//             return max(nums[start] + robhelper(start + 2, end),
//                        robhelper(start + 1, end));
//         // start > end
//         return 0;
//     }

//   public:
//     int rob(vector<int> &nums) { return robhelper(nums, 0, nums.size() - 1);
//     }
// };