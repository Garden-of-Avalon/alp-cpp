// Given an array of size n, find the majority element. The majority element is
// the element that appears more than ⌊ n/2 ⌋ times.
// You may assume that the array is non-empty and the majority element always
// exist in the array.
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

// notice this solution must require
// the element that appears more than ⌊ n/2 ⌋ times.
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int counter = 0, result;
        for (auto &n : nums) {
            if (!counter) {
                result = n;
                ++counter;
            } else if (n == result)
                ++counter;
            else
                --counter;
        }
        return result;
    }
};