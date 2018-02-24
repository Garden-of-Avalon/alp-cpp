//  Given a string S and a string T, count the number of distinct subsequences
//  of S which equals T.

// A subsequence of a string is a new string which is formed from the original
// string by deleting some (can be none) of the characters without disturbing
// the relative positions of the remaining characters. (ie, "ACE" is a
// subsequence of "ABCDE" while "AEC" is not).

// Here is an example:
// S = "rabbbit", T = "rabbit"

// Return 3.

// pseudo dp self version
class Solution {
  public:
    int numDistinct(string s, string t) {
        // cache friendly since s.size() is usually longger
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1, -1));

        function<int(int, int)> helper = [&](int si, int ti) {
            if (dp[ti][si] >= 0)
                return dp[ti][si];

            int oldsi = si, ret = 0;

            while (si != s.size() && s[si] != t[ti])
                ++si;

            if (si != s.size())
                ret = helper(si + 1, ti) +
                      (ti == t.size() - 1 ? 1 : helper(si + 1, ti + 1));

            fill_n(dp[ti].begin() + oldsi, si - oldsi, ret);

            return ret;
        };

        return helper(0, 0);
    }
};

// dp ref version
class Solution {
  public:
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size() + 1, vector<int>(s.size() + 1));

        // because for t.substr(0,0), this can be considered as a match
        fill(dp[0].begin(), dp[0].end(), 1);

        // dp[j][i] means the number of ways of
        // s.substr(0, i) can match with t.substr(0, j)

        for (int i = 1; i <= s.size(); ++i)
            for (int j = 1; j <= t.size(); ++j)
                dp[j][i] = dp[j][i - 1] +
                           (s[i - 1] == t[j - 1] ? dp[j - 1][i - 1] : 0);

        return dp[t.size()][s.size()];
    }
};

// TLE recursive
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         function<int(int,int)> helper = [&](int si, int ti) {
//             while(si != s.size() && s[si] != t[ti])
//                 ++si;

//             if(si == s.size())
//                 return 0;

//             return helper(si + 1, ti) + (ti == t.size() - 1 ? 1 : helper(si +
//             1, ti + 1));
//         };

//         return helper(0, 0);
//     }
// };