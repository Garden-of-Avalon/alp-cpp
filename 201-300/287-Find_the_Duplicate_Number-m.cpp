//  Given an array nums containing n + 1 integers where each integer is between
//  1 and n (inclusive), prove that at least one duplicate number must exist.
//  Assume that there is only one duplicate number, find the duplicate one.

// Note:

//     You must not modify the array (assume the array is read only).
//     You must use only constant, O(1) extra space.
//     Your runtime complexity should be less than O(n2).
//     There is only one duplicate number in the array, but it could be repeated
//     more than once.

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

// O(nlogn), O(1)
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int low = 1;
        int high = nums.size() - 1;
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            int count = 0;
            for (auto &n : nums)
                if (n <= mid)
                    ++count;
            if (count > mid)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

// O(n), O(1), ref 142
class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int slow = 0;
        int fast = 0;
        int finder = 0;

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        while (slow != finder) {
            slow = nums[slow];
            finder = nums[finder];
        }

        return finder;
    }
};
