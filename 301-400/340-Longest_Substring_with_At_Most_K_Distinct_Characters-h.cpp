// Given a string, find the length of the longest substring T that contains at
// most k distinct characters.

// Example 1:

// Input: s = "eceba", k = 2
// Output: 3
// Explanation: T is "ece" which its length is 3.
// Example 2:

// Input: s = "aa", k = 1
// Output: 2
// Explanation: T is "aa" which its length is 2.

// Ref: 904, 159
class Solution {
  public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int uniques = 0, ret = 0, l = 0;
        vector<int> m(256);

        for (int r = 0; r < s.size(); ++r) {
            uniques += m[s[r]]++ == 0;
            while (uniques > k)
                uniques -= --m[s[l++]] == 0;
            ret = max(ret, r - l + 1);
        }

        return ret;
    }
};