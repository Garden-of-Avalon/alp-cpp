// Given an array S of n integers, are there elements a, b, c, and d in S such
// that a + b + c + d = target? Find all unique quadruplets in the array which
// gives the sum of target.
// Note: The solution set must not contain duplicate quadruplets.
// For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]

// use O(n^2) 3sum helper
class Solution {
    void threeSumSorted(vector<vector<int>> &res, vector<int> &nums, int start,
                        int target) {
        // O(n^2)
        for (int i = start; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target)
                    do {
                        ++j;
                    } while (j < k && nums[j] == nums[j - 1]);
                else if (sum > target)
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                else {
                    // acutally i, j, k; just combine j++ and k-- here.
                    res.push_back(
                        {nums[start - 1], nums[i], nums[j++], nums[k--]});
                    // bypassing same elements (j, k)
                    while (j < k && nums[j] == nums[j - 1])
                        ++j;
                    while (j < k && nums[k] == nums[k + 1])
                        --k;
                }
            }
            // bypassing same elements (i)
            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                ++i;
        }
        return;
    }

  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        if (nums.size() < 4)
            return res;

        sort(nums.begin(), nums.end()); // nlog(n)

        for (int i = 0; i < nums.size() - 3; ++i) {
            if (nums[i] + nums.back() * 3 >= target && nums[i] * 4 <= target)
                threeSumSorted(res, nums, i + 1, target - nums[i]);
            // bypassing same elements
            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                ++i;
        }

        return res;
    }
};