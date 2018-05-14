// Given an array with n integers, your task is to check if it could become
// non-decreasing by modifying at most 1 element.

// We define an array is non-decreasing if array[i] <= array[i + 1] holds for
// every i (1 <= i < n).

// Example 1:
// Input: [4,2,3]
// Output: True
// Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
// Example 2:
// Input: [4,2,1]
// Output: False
// Explanation: You can't get a non-decreasing array by modify at most one
// element. Note: The n belongs to [1, 10,000].

class Solution {
  public:
    bool checkPossibility(vector<int> &nums) {
        bool once = false; // decrease once

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] > nums[i]) {
                // case 1: 4, 2, 3
                //         ^
                // case 2: 1, 3, 3, 2, 4
                //                  ^
                if (!once &&
                    (i == 1 || nums[i - 2] <= nums[i] ||
                     i == nums.size() - 1 || nums[i - 1] <= nums[i + 1])) {
                    once = true;
                    continue;
                }
                return false;
            }
        }

        return true;
    }
};