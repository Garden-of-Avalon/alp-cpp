// Given a non-empty string s and a dictionary wordDict containing a list of
// non-empty words, determine if s can be segmented into a space-separated
// sequence of one or more dictionary words. You may assume the dictionary does
// not contain duplicate words.
// For example, given
// s = "leetcode",
// dict = ["leet", "code"].
// Return true because "leetcode" can be segmented as "leet code".
// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a
// set of strings). Please reload the code definition to get the latest changes.

// DP
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        // dp[i] is true means s[0..i) can be segmented ...
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                // check previous (dp[i - 1]) first
                // if dp[j] is true, just need to check s[j, i)
                if (dp[j]) {
                    if (std::find(wordDict.begin(), wordDict.end(),
                                  s.substr(j, i - j)) != wordDict.end()) {
                        dp[i] = true;
                        // break inner for loop
                        // check next i
                        break;
                    }
                }
                // if not check previous ones, --j
            }
        }
        return dp[s.size()];
    }
};