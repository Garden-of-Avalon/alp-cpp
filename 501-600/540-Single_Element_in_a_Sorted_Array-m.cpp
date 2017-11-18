// Given a sorted array consisting of only integers where every element appears
// twice except for one element which appears once. Find this single element
// that appears only once.
// Example 1:
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
// Example 2:
// Input: [3,3,7,7,10,11,11]
// Output: 10
// Note: Your solution should run in O(log n) time and O(1) space.

class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        if (nums.empty())
            return 0;

        int l = 0, r = nums.size() - 1, mid;

        while (l < r) {
            mid = (l + r) / 2;

            // mid is odd, first half is even
            // if (mid % 2) {
            //     if (nums[mid] == nums[mid - 1])
            //         l = mid + 1;
            //     else
            //         r = mid - 1;
            // } else {
            //     if (nums[mid] == nums[mid + 1])
            //         l = mid + 1;
            //     else
            //         r = mid - 1;
            // }

            if (nums[mid] == nums[mid ^ 1])
                l = mid + 1;
            else
                r = mid - 1;
        }

        return nums[l];
    }
};