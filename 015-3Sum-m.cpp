// Given an array S of n integers, are there elements a, b, c in S such that a +
// b + c = 0? Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.
// For example, given array S = [-1, 0, 1, 2, -1, -4],
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        if (*num.begin() > 0 || *(nums.end() - 1) < 0)
            return vector<vector<int>>();

        set<vector<int>> result;
        if (nums[i] + nums[j] > 0)

            return vector<vector<int>>(result.begin(), result.end());
    }
};