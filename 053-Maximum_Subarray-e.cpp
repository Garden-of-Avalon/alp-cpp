// Find the contiguous subarray within an array (containing at least one number)
// which has the largest sum.
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.
// More practice:
// If you have figured out the O(n) solution, try coding another solution using
// the divide and conquer approach, which is more subtle

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        if (nums.empty())
            return 0;
        vector<int> temp(nums.size());
        int result = temp[0] = nums[0];
        // in each iteration, temp[i] can remember sum(... , nums[i-1], nums[i])
        // if we update result with temp, "contiguous" is still hold
        for (int i = 1; i < nums.size(); ++i)
            result =
                max(result,
                    temp[i] = nums[i] + (temp[i - 1] > 0 ? temp[i - 1] : 0));
        return result;
    }
};