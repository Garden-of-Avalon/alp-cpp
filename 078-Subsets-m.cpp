// Given a set of distinct integers, nums, return all possible subsets.
// Note: The solution set must not contain duplicate subsets.
// For example,
// If nums = [1,2,3], a solution is:
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        // using std::pow
        // we know the result have 2^n elements
        // result size rsz = sum of combination number
        int sz = nums.size(), rsz = pow(2, sz);
        vector<vector<int>> result(rsz, vector<int>());

        int i, j, k, l = 1, temp;
        // because we do not need rsz origal value, initialize as half
        for (k = 0, rsz >>= 1; k < sz; ++k, l <<= 1, rsz >>= 1) {
            for (j = 0; j < l; ++j) {
                temp = j * rsz * 2;
                for (i = 0; i < rsz; ++i) {
                    result[temp + i].push_back(nums[k]);
                }
            }
        }
        // 3
        // 2   2   3       3
        // 1   1   1   1   2   2   3   []
        return result;
    }
};
