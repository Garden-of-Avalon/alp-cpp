// Given an integer array, you need to find one continuous subarray that if you
// only sort this subarray in ascending order, then the whole array will be
// sorted in ascending order, too.
// You need to find the shortest such subarray and output its length.
// Example 1:
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the
// whole array sorted in ascending order.
// Note:
//     Then length of the input array is in range [1, 10,000].
//     The input array may contain duplicates, so ascending order here means <=.

// IMPORTANT
class Solution {
  public:
    int findUnsortedSubarray(vector<int> &nums) {
        int n = nums.size();
        int h = -1, t = -2;
        int maxval = nums[0], minval = nums[n - 1];
        for (int i = 1; i < n; ++i) {
            minval = std::min(minval, nums[n - 1 - i]);
            maxval = std::max(maxval, nums[i]);
            if (nums[i] < maxval)
                t = i;
            if (nums[n - 1 - i] > minval)
                h = n - 1 - i;
        }
        return t - h + 1;
    }
};