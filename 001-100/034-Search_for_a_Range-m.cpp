// Given an array of integers sorted in ascending order, find the starting and
// ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        // for C++20, use equal_range
        int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin();

        if (l == r)
            return {-1, -1};

        if (l == r - 1)
            return {l, l};

        return {l, r - 1};
    }
};

// implementation of lower_bound which return index
// int my_lower_bound(vector<int> &nums, int l, int r, int target) {
//     while (l <= r) {
//         int mid = l + (r - l) / 2;
//         if (nums[mid] < target)
//             l = mid + 1;
//         else if (nums[mid] > target)
//             r = mid - 1;
//         else
//             return mid;
//     }
//     return l;
// }