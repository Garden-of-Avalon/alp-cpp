//  Given a string S, you are allowed to convert it to a palindrome by adding
//  characters in front of it. Find and return the shortest palindrome you can
//  find by performing this transformation.

// For example:

// Given "aacecaaa", return "aaacecaaa".

// Given "abcd", return "dcbabcd".

// Credits:
// Special thanks to @ifanchu for adding this problem and creating all test
// cases. Thanks to @Freezen for additional test cases.

// Manacher's algorithm, O(n)
class Solution {
    string prepare(const string &s) {
        stringstream Ts;
        Ts << '^';
        for (auto &&c : s)
            Ts << '#' << c;
        if (!s.empty())
            Ts << '#';
        Ts << '$';
        return Ts.str();
    }

  public:
    string shortestPalindrome(string s) {
        string T = prepare(s);   // transformed string
        vector<int> P(T.size()); // longest palindrome

        int C = 0, R = 0; // center, right
        // for (int i = 1; i < T.size() - 1; ++i) {
        int hsz = T.size() / 2 + 1;
        // actually to half size is enough,
        // after half size, pl cannot extend to beginning
        for (int i = 1; i < hsz; ++i) {
            P[i] = R > i ? min(R - i, P[2 * C - i]) : 0;

            while (T[i + P[i] + 1] == T[i - P[i] - 1])
                ++P[i];

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        // get longest pl which also extend to beginning
        int pl_i = 0, pl_len = 0;
        for (int i = 1; i < hsz; ++i)
            if (pl_len < P[i] && i == P[i] + 1) {
                pl_len = P[i];
                pl_i = i;
            }

        string prefix = s.substr((pl_i + pl_len) / 2, s.size());
        reverse(prefix.begin(), prefix.end());

        return prefix + s;
    }
};

// KMP, O(n)
class Solution {
  public:
    string shortestPalindrome(string s) {
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        string pat = s + '#' + s_rev;

        // lps
        int len = 0, i = 1, m = pat.size();
        vector<int> lps(m);
        while (i < m) {
            if (pat[i] == pat[len]) {
                ++len;
                lps[i++] = len;
            } else if (len == 0)
                lps[i++] = 0;
            else
                len = lps[len - 1];
        }

        return s_rev.substr(0, s_rev.size() - lps[m - 1]) + s;
    }
};