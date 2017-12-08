// Given an array S of n integers, find three integers in S such that the sum is
// closest to a given number, target. Return the sum of the three integers. You
// may assume that each input would have exactly one solution.
//     For example, given array S = {-1 2 1 -4}, and target = 1.
//     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
  public:
    int threeSumClosest(vector<int> &nums, int target) {
        // if (nums.size() < 3)
        //     throw std::runtime_error("wrong size");

        sort(nums.begin(), nums.end());

        // assume overflow won't happen
        int res, diff = INT_MAX;

        // O(n^2)
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = nums.size() - 1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (abs(target - sum) < diff) {
                    if ((diff = abs(target - sum))) // diff != 0
                        res = sum;
                    else
                        return sum;
                }

                if (sum < target)
                    do {
                        ++j;
                    } while (j < k && nums[j] == nums[j - 1]);
                else if (sum > target)
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
            }
            // bypassing same elements (i)
            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                ++i;
        }
        return res;
    }
};