// Suppose an array sorted in ascending order is rotated at some pivot unknown
// to you beforehand.
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
// Find the minimum element.
// You may assume no duplicate exists in the array.

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int h = 0, t = nums.size() - 1;
        while (h < t) {
            if (nums[h] < nums[t])
                return nums[h];

            int mid = (h + t) / 2;
            // possible: h == mid == 0
            if (nums[h] <= nums[mid])
                h = mid + 1;
            else
                t = mid;
        }
        return nums[h];
    }
};