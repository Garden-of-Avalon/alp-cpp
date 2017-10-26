// Implement regular expression matching with support for '.' and '*'.
// '.' Matches any single character.
// '*' Matches zero or more of the preceding element.
// The matching should cover the entire input string (not partial).
// The function prototype should be:
// bool isMatch(const char *s, const char *p)
// Some examples:
// isMatch("aa","a") → false
// isMatch("aa","aa") → true
// isMatch("aaa","aa") → false
// isMatch("aa", "a*") → true
// isMatch("aa", ".*") → true
// isMatch("ab", ".*") → true
// isMatch("aab", "c*a*b") → true

class Solution {
  public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();

        if (p[1] == '*')
            // Case 1: p[0] s[0] don't care; s matches p[2..]
            // including both p[2..], s are empty
            // Case 2: s[0] matches p[0] AND s[1..] matches p
            // && has higher precedence than ||
            return isMatch(s, p.substr(2)) ||
                   !s.empty() && (s[0] == p[0] || '.' == p[0]) &&
                       isMatch(s.substr(1), p);
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) &&
                   isMatch(s.substr(1), p.substr(1));
    }
};

// DP
class Solution {
  public:
    bool isMatch(string s, string p) {
        int ssz = s.size(), psz = p.size();
        vector<vector<bool>> tf(ssz + 1, vector<bool>(psz + 1, false));
        tf[0][0] = true;
        for (int i = 0; i <= ssz; ++i) {
            for (int j = 1; j <= psz; ++j) {
                if (p[j - 1] == '*') {
                    // (for valid input)
                    // j - 2 is safe since * goes along with preceding char
                    // s matches (...)a*, s.last != a, tf[i][j] = tf[i][j-2]
                    // s matches (...)a*, s.last == a, tf[i][j] = tf[i-1][j]
                    tf[i][j] = tf[i][j - 2] ||
                               i > 0 &&
                                   (s[i - 1] == p[j - 2] || '.' == p[j - 2]) &&
                                   tf[i - 1][j];
                } else {
                    // check s[i - 1] p[j - 1] matching and tf[i-1][j-1]
                    tf[i][j] = i > 0 &&
                               (s[i - 1] == p[j - 1] || '.' == p[j - 1]) &&
                               tf[i - 1][j - 1];
                }
            }
        }
        return tf[ssz][psz];
    }
};