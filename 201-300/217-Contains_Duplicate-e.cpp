// Given an array of integers, find if the array contains any duplicates. Your
// function should return true if any value appears at least twice in the array,
// and it should return false if every element is distinct.

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> record;
        for (auto &&n : nums)
            if (!record.insert(n).second)
                return true;
        return false;
    }
};

class Solution {
  public:
    bool containsDuplicate(vector<int> &nums) {
        return set<int>(nums.begin(), nums.end()).size() < nums.size();
    }
}