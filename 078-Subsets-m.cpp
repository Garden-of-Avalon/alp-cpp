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

// O(2^n), better
// Recursive Backtrace
class Solution {
    void genSubsets(vector<int> &nums, int start, vector<int> &currIn,
                    vector<vector<int>> &result) {
        result.push_back(currIn);
        for (int i = start; i < nums.size(); ++i) {
            currIn.push_back(nums[i]);
            genSubsets(nums, i + 1, currIn, result);
            currIn.pop_back();
        }
    }
    // Example:
    /* At second layer of genSubset()
        sub == {1}
        subs.push({1})

        for 1st
            sub = {1, 2}
            recursion
            subs.pop

        for 2nd
            sub = {1, 3}
            recursion
            subs.pop
    */

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        // using std::pow
        // we know the result have 2^n elements
        // result size rsz = sum of combination number
        int sz = nums.size(), rsz = pow(2, sz);
        vector<vector<int>> result;
        vector<int> currIn;

        genSubsets(nums, 0, currIn, result);
        return result;
    }
};

// O(2^n), not good
// Exactly equivalent to Bit Manipulation
// class Solution {
//   public:
//     vector<vector<int>> subsets(vector<int> &nums) {
//         // using std::pow
//         // we know the result have 2^n elements
//         // result size rsz = sum of combination number
//         int sz = nums.size(), rsz = pow(2, sz);
//         vector<vector<int>> result(rsz, vector<int>());

//         int i, j, k, l = 1, temp;
//         // because we do not need rsz origal value, initialize as half
//         for (k = 0, rsz >>= 1; k < sz; ++k, l <<= 1, rsz >>= 1) {
//             for (j = 0; j < l; ++j) {
//                 temp = j * rsz * 2;
//                 for (i = 0; i < rsz; ++i) {
//                     result[temp + i].push_back(nums[k]);
//                 }
//             }
//         }
//         // 3
//         // 2   2   3       3
//         // 1   1   1   1   2   2   3   []
//         return result;
//     }
// };

// Bit Manipulation
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int num_subset = pow(2, nums.size());
//         vector<vector<int> > res(num_subset, vector<int>());
//         for (int i = 0; i < nums.size(); i++)
//             for (int j = 0; j < num_subset; j++)
//                 if ((j >> i) & 1)
//                     res[j].push_back(nums[i]);
//         return res;
//     }
// };
// [], [], [], [], [], [], [], []
// [], [1], [], [1], [], [1], [], [1]
// [], [1], [2], [1, 2], [], [1], [2], [1, 2]
// [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]