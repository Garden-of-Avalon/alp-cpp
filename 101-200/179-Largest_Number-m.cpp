// Given a list of non negative integers, arrange them such that they form the
// largest number. For example, given [3, 30, 34, 5, 9], the largest formed
// number is 9534330. Note: The result may be very large, so you need to return
// a string instead of an integer.
// Credits: Special thanks to @ts for adding this problem and creating all test
// cases.

class Solution {
  public:
    string largestNumber(vector<int> &nums) {
        vector<string> strs;
        transform(nums.begin(), nums.end(), back_inserter(strs),
                  [](auto &i) { return to_string(i); });

        sort(strs.begin(), strs.end(), [](const string &s1, const string &s2) {
            return s1 + s2 > s2 + s1;
        });

        if (strs.size() > 0 && strs[0] == "0")
            return "0";

        string ret;
        for_each(strs.begin(), strs.end(), [&](const auto &s) { ret += s; });

        return ret;
    }
};