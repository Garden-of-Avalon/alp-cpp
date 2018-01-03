// Given an unsorted integer array, find the first missing positive integer.

// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.

// Your algorithm should run in O(n) time and uses constant space.

// O(1) space and O(n) time
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        for (int i = 0; i < nums.size(); i++)
            while (nums[i] > 0 && nums[i] <= nums.size() &&
                   nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] != i + 1)
                return i + 1;

        return nums.size() + 1;
    }
};

// O(n) space and O(n) time
class Solution {
  public:
    int firstMissingPositive(vector<int> &nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() + 2; i++) {
            if (numset.find(i) == numset.end())
                return i;
        }
        return 1;
    }
};