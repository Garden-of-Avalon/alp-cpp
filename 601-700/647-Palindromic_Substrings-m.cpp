//  Given a string, your task is to count how many palindromic substrings in
//  this string.

// The substrings with different start indexes or end indexes are counted as
// different substrings even they consist of same characters.

// Example 1:

// Input: "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".

// Example 2:

// Input: "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

// Note:

//     The input string length won't exceed 1000.

// Manacher’s Algorithm
// https://articles.leetcode.com/longest-palindromic-substring-part-ii/
// https://www.felix021.com/blog/read.php?2040
class Solution {
    string prepare(const string &s) {
        stringstream Ts("^");
        for (auto &&c : s)
            Ts << '#' << c;
        if (!s.empty())
            Ts << '#';
        Ts << '$';
        return Ts.str();
    }

  public:
    int countSubstrings(string s) {
        string T = prepare(s); // transformed string
        vector<int> P(T.size()); // longest palindrome

        int C = 0, R = 0; // center, right

        for(int i = 1; i < T.size() - 1; ++i) {
            P[i] = R > i ? min(R - i, P[2 * C - i]) : 0;

            while (T[i + P[i] + 1] == T[i - P[i] - 1])
                ++P[i];
            
            if(i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        int ret = 0;

        for(auto &&pl : P)
            ret += (pl + 1) / 2;

        return ret;
    }
};