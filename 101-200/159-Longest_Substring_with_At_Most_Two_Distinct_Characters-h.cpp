// Given a string s , find the length of the longest substring t  that contains
// at most 2 distinct characters.

// Example 1:

// Input: "eceba"
// Output: 3
// Explanation: t is "ece" which its length is 3.
// Example 2:

// Input: "ccaabbb"
// Output: 5
// Explanation: t is "aabbb" which its length is 5.

class Solution {
  public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.empty())
            return 0;

        char c1 = s[0], c2 = s[0];
        int ret = 1, curr_len = 1;
        int first_pos = 0; // for "ccaabbb", i = 3, s[i] is 'a', first_pos = 2

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == c2 || s[i] == c1) {
                ++curr_len;
                if (s[i] != s[i - 1])
                    first_pos = i;
            } else {
                ret = max(ret, curr_len);
                curr_len = i - first_pos + 1;
                c1 == s[first_pos] ? (c2 = s[i]) : (c1 = s[i]);
                first_pos = i;
            }
        }

        return max(ret, curr_len);
    }
};