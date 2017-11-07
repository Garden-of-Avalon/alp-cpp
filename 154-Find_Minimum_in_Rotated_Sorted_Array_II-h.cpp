//     Follow up for "Find Minimum in Rotated Sorted Array":
//     What if duplicates are allowed?
//     Would this affect the run-time complexity? How and why?
// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// The array may contain duplicates.

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int h = 0, t = nums.size() - 1;
        while (h < t) {
            if (nums[h] < nums[t])
                return nums[h];

            int mid = (h + t) / 2;
            if (nums[h] < nums[mid])
                h = mid + 1;
            else if (nums[h] == nums[mid]) // Important
                ++h;
            else // nums[h] > nums[mid]
                t = mid;
        }
        return nums[h];
    }
};