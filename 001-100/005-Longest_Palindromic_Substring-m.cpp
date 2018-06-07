// Given a string s, find the longest palindromic substring in s. You may assume
// that the maximum length of s is 1000.
// Example:
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
// Example:
// Input: "cbbd"
// Output: "bb"

// TODO: Manacher's algorithm

// expand from center
class Solution {
    // return start index and size of substr
    pair<int, int> expand(const string &s, int l, int r) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return make_pair(l + 1, r - l - 1);
    }

    void update(string &ret, const string &s, const pair<int, int> &st_sz) {
        if (st_sz.second > ret.size())
            ret = s.substr(st_sz.first, st_sz.second);
    }

  public:
    string longestPalindrome(string s) {
        string ret;

        for (int i = 0; i < s.size(); ++i) {
            update(ret, s, expand(s, i, i));
            update(ret, s, expand(s, i, i + 1));
        }

        return ret;
    }
};

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