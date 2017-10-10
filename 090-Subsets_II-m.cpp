// Given a collection of integers that might contain duplicates, nums, return
// all possible subsets.
// Note: The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,2], a solution is:
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]

// TODO
// Similar to 078
// use iterative way
class Solution {
  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        int sz = nums.size(), rsz = pow(2, sz);
        vector<vector<int>> result(1, vector<int>());

        int i, j, k;
        for (int i = 0; i < sz; ++i) {
            k = result.size();
            for (int j = 0; j < k; ++j) {
                result.push_back(result[j]);
                result.back().push_back(nums[i]);
            }
        }

        return result;
    }
};