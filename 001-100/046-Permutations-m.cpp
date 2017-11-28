//  Given a collection of distinct numbers, return all possible permutations.
// For example,
// [1,2,3] have the following permutations:
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]

// Recursive Backtracking
class Solution {
    void genPermu(vector<int> &nums, int start, vector<vector<int>> &result) {
        if (start == nums.size())
            result.push_back(nums);
        else {
            for (int i = start; i < nums.size(); ++i) {
                swap(nums[start], nums[i]);
                genPermu(nums, start + 1, result);
                swap(nums[start], nums[i]);
            }
        }
    }

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> result;
        genPermu(nums, 0, result);
        return result;
    }
};