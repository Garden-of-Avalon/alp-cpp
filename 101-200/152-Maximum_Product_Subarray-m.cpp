// Find the contiguous subarray within an array (containing at least one number)
// which has the largest product.
// For example, given the array [2,3,-2,4],
// the contiguous subarray [2,3] has the largest product = 6.


class Solution {
public:
  int maxProduct(vector<int> &nums) {
      int ret = nums[0], tmax = nums[0], tmin = nums[0];

      for (int i = 1; i < nums.size(); ++i) {
          if (nums[i] < 0) 
              swap(tmax,tmin);
          
          tmax = max(nums[i], tmax * nums[i]);
          // to record current small number
          // if nums[i] < 0 and tmin < 0, tmin will be nums[i]
          tmin = min(nums[i], tmin * nums[i]);
          
          ret = max(tmax, ret);         
      }
      
      return ret;
  }
};