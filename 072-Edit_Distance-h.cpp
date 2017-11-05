// Given two words word1 and word2, find the minimum number of steps required to
// convert word1 to word2. (each operation is counted as 1 step.)
// You have the following 3 operations permitted on a word:
// a) Insert a character
// b) Delete a character
// c) Replace a character

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int sz1 = word1.size(), sz2 = word2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));

        // d[i][j] means the steps need to convert word1[0..i) to word2[0..j)

        // delete n chars, convert to ""
        for (int i = 0; i <= sz1; ++i)
            dp[i][0] = i;

        // add n chars, convert from "" to word2[0,j)
        for (int j = 0; j <= sz2; ++j)
            dp[0][j] = j;

        for (int i = 1; i <= sz1; ++i) 
            for (int j = 1; j <= sz2; ++j) 
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j - 1] + 1,
                                   min(dp[i][j - 1] + 1, dp[i - 1][j] + 1));
                // replace a char: dp[i - 1][j - 1] + 1
                // delete a char: dp[i][j - 1] + 1
                // add a char: dp[i][j - 1] + 1
            
        return dp[sz1][sz2];
    }
};