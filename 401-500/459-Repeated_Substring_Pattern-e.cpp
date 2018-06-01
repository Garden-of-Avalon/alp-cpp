// Given a non-empty string check if it can be constructed by taking a substring
// of it and appending multiple copies of the substring together. You may assume
// the given string consists of lowercase English letters only and its length
// will not exceed 10000. Example 1: Input: "abab"

// Output: True

// Explanation: It's the substring "ab" twice.
// Example 2:
// Input: "aba"

// Output: False
// Example 3:
// Input: "abcabcabcabc"

// Output: True

// Explanation: It's the substring "abc" four times. (And the substring "abcabc"
// twice.)

// ref:
// https://leetcode.com/problems/repeated-substring-pattern/discuss/94334/Easy-python-solution-with-explaination
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        string ss_part = s.substr(1) + s.substr(0, s.size() - 1);
        return ss_part.find(s) != string::npos;
    }
};

// another good method
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int mid = s.size() / 2;
        for (int i = 1; i <= mid; ++i)
            if (s.size() % i == 0 && s.substr(i) == s.substr(0, s.size() - i))
                return true;
        return false;
    }
};

// KMP ref:
// https://leetcode.com/problems/repeated-substring-pattern/discuss/94397/C++-O(n)-using-KMP-32ms-8-lines-of-code-with-brief-explanation.
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int i = 1, len = 0, sz = s.size();
        vector<int> lps(sz);

        while (i < sz) {
            if (s[i] == s[len])
                lps[i++] = ++len;
            else if (len == 0)
                ++i;
            else
                len = lps[len - 1];
        }

        return lps[sz - 1] && lps[sz - 1] % (sz - lps[sz - 1]) == 0;
    }
};

// my own version
class Solution {
  public:
    bool repeatedSubstringPattern(string s) {
        int mid = s.size() / 2;

        if (s.substr(0, mid) == s.substr(mid))
            return true;

        // add a period
        for (int i = 0; i < mid; ++i)
            if (s.substr(0, i + 1) == s.substr(s.size() - 1 - i)) {
                int temp_mid = (s.size() + i + 1) / 2;
                if (s.substr(0, temp_mid) ==
                    s.substr(temp_mid) + s.substr(0, i + 1))
                    return true;
            }

        return false;
    }
};