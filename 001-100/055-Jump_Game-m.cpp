//  Given an array of non-negative integers, you are initially positioned at the
//  first index of the array.

// Each element in the array represents your maximum jump length at that
// position.

// Determine if you are able to reach the last index.

// For example:
// A = [2,3,1,1,4], return true.

// A = [3,2,1,0,4], return false.

class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        if (n < 2)
            return true;

        int right = nums[0];

        for (int i = 1; i <= right; ++i) {
            if (nums[i] > 0)
                right = max(right, i + nums[i]);
            if (right >= n - 1)
                return true;
        }
        return false;
    }
};

// ref: from back
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        int right = nums.size() - 1;

        for (int i = right - 1; i >= 0; --i)
            if (i + nums[i] >= right)
                right = i;

        return right <= 0; // take care nums.size() == 0
    }
};
;