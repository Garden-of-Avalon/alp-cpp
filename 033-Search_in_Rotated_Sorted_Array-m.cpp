// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// You are given a target value to search. If found in the array return its
// index, otherwise return -1.
// You may assume no duplicate exists in the array.

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty())
            return -1;

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (target == nums[m])
                return m;

            if (nums[l] <= target && target <= nums[m])
                r = m;
            else if (nums[m] <= target && target <= nums[r])
                l = m + 1; // important
            else if (nums[l] <= nums[m])
                l = m + 1;
            else if (nums[m] <= nums[r])
                r = m - 1;
        }

        return target == nums[l] ? l : -1;
    }
};