// A peak element is an element that is greater than its neighbors.

// Given an input array where num[i] ≠ num[i+1], find a peak element and return
// its index.

// The array may contain multiple peaks, in that case return the index to any
// one of the peaks is fine.

// You may imagine that num[-1] = num[n] = -∞.

// For example, in array [1, 2, 3, 1], 3 is a peak element and your function
// should return the index number 2.

// click to show spoilers.
// Note:

// Your solution should be in logarithmic complexity.

// binary search
class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        int cand = INT_MIN;
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            // max_mid == r - 1, since l < r
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[mid + 1]) {
                cand = max(cand, nums[mid + 1]);
                l = mid + 1;
            } else { // since nums[i] != nums[i + 1], nums[mid] > nums[mid + 1]
                if (mid == 0 || nums[mid - 1] < nums[mid])
                    return mid;

                // nums[mid - 1] > nums[mid]
                cand = max(cand, nums[mid - 1]);
                r = mid - 1;
            }
        }

        return l;
    }
};