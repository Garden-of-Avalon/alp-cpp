// Given a non-empty string s and a dictionary wordDict containing a list of
// non-empty words, add spaces in s to construct a sentence where each word is a
// valid dictionary word. You may assume the dictionary does not contain
// duplicate words.
// Return all such possible sentences.
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
// A solution is ["cats and dog", "cat sand dog"].
// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a
// set of strings). Please reload the code definition to get the latest changes.

// similar to 139
// at success, don't go to next i but continue checking until j == 0
class Solution {
  public:
    vector<string> wordBreak(string s, vector<string> &wordDict) {
        // check first
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        vector<int> trueIndex = {0};
        for (int i = 1; i <= s.size(); ++i)
            for (int j = i - 1; j >= 0; --j)
                if (dp[j] &&
                    std::find(wordDict.begin(), wordDict.end(),
                              s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    trueIndex.push_back(i);
                    break;
                }
        if (!dp[s.size()])
            return vector<string>();

        unordered_map<int, vector<string>> resAt;
        for (int &i : trueIndex)
            for (int &j : trueIndex)
                if (j >= i)
                    break;
                else if (std::find(wordDict.begin(), wordDict.end(),
                                   s.substr(j, i - j)) == wordDict.end())
                    continue;
                else if (j) {
                    resAt[i].insert(resAt[i].end(), resAt[j].begin(),
                                    resAt[j].end());
                    for (int k = 0, sz = resAt[i].size(); k < resAt[j].size();
                         ++k)
                        resAt[i][sz - 1 - k] += ' ' + s.substr(j, i - j);
                } else // j == 0
                    resAt[i].push_back(s.substr(0, i));
        return resAt[s.size()];
    }
};

// second part original, also 6 ms
// for (int i = 1; i <= s.size(); ++i)
//     if (dp[i])
//         for (int j = i - 1; j >= 0; --j)
//             if (dp[j] &&
//                 std::find(wordDict.begin(), wordDict.end(),
//                           s.substr(j, i - j)) != wordDict.end()) {
//                 if (j) {
//                     resAt[i].insert(resAt[i].end(), resAt[j].begin(),
//                                     resAt[j].end());
//                     for (int k = 0, sz = resAt[i].size();
//                          k < resAt[j].size(); ++k)
//                         resAt[i][sz - k - 1] +=
//                             ' ' + s.substr(j, i - j);
//                 } else {
//                     // j == 0
//                     resAt[i].push_back(s.substr(0, i));
//                     // safe to change ret due to go out of loop
//                 }
//             }

// similar but concise from leetcode discussion
// vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
//     unordered_map<int, vector<string>> memo {{s.size(), {""}}};
//     function<vector<string>(int)> sentences = [&](int i) {
//         if (!memo.count(i))
//             for (int j=i+1; j<=s.size(); j++)
//                 if (wordDict.count(s.substr(i, j-i)))
//                     for (string tail : sentences(j))
//                         memo[i].push_back(s.substr(i, j-i) + (tail=="" ? "" :
//                         ' ' + tail));
//         return memo[i];
//     };
//     return sentences(0);
// }