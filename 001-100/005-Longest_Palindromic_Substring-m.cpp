// Given a string s, find the longest palindromic substring in s. You may assume
// that the maximum length of s is 1000.
// Example:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example:
// Input: "cbbd"
// Output: "bb"


// TODO: expand around center; Manacher's algorithm

class Solution {
    bool checkPalindrome(const string &s, int start, int end) {
        while (start < end)
            if (s[start++] != s[end--])
                return false;
        return true;
    }

  public:
    string longestPalindrome(string s) {
        int len = s.size(), i;
        if (len == 0)
            return "";
        for (int substrlen = len; substrlen > 0; --substrlen)
            for (i = 0; i < len - substrlen + 1; ++i)
                if (checkPalindrome(s, i, i + substrlen - 1))
                    return s.substr(i, substrlen);
    }
};