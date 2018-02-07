// Given an array of integers, 1 ≤ a[i] ≤ n (n = size of array), some elements
// appear twice and others appear once.

// Find all the elements that appear twice in this array.

// Could you do it without extra space and in O(n) runtime?

// Example:

// Input:
// [4,3,2,7,8,2,3,1]

// Output:
// [2,3]

// method 1
class Solution {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> ret;

        for (int i = 0; i < nums.size(); ++i)
            while (nums[i] && nums[i] != i + 1)
                if (nums[i] == nums[nums[i] - 1]) {
                    ret.push_back(nums[i]);
                    nums[i] = 0; // mark
                    break;
                } else
                    // put n at nums[n - 1]
                    swap(nums[i], nums[nums[i] - 1]);

        return ret;
    }
};

// method 2
class Solution {
  public:
    vector<int> findDuplicates(vector<int> &nums) {
        vector<int> ret;

        for (auto &&n : nums) {
            int absn = abs(n);

            if (nums[absn - 1] < 0)
                ret.push_back(absn);
            else
                nums[absn - 1] *= -1;
        }

        return ret;
    }
};