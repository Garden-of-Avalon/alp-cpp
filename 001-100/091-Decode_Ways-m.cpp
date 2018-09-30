//  A message containing letters from A-Z is being encoded to numbers using the
//  following mapping:

// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26

// Given an encoded message containing digits, determine the total number of
// ways to decode it.

// For example,
// Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

// The number of ways decoding "12" is 2.

class Solution {
  public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;

        vector<int> dp(s.size() + 2, 1);

        bool m1 = false, m2 = false; // mark1, mark2
        for (int i = 0; i < s.size(); ++i) {
            int t = s[i] - '0'; // t == 1 if s[i] == 1

            // WTF
            if (t == 0 && !m1 && !m2 || t > 9)
                return 0;

            if (t == 0 && (m1 || m2))
                dp[i + 2] = dp[i];
            else if (m1 || m2 && t < 7)
                dp[i + 2] = dp[i] + dp[i + 1];
            else
                dp[i + 2] = dp[i + 1];

            if (t == 1 || t == 2)
                m2 = ~(m1 = t << 31);
            else
                m1 = m2 = false;
        }

        return dp[s.size() + 1];
    }
};

// better DP
class Solution {
  public:
    int numDecodings(string s) {
        if (s.empty())
            return 0;

        // previous, previous of previous
        int pWays = s.back() != '0', ppWays = 1;

        for (int i = s.size() - 2; i >= 0; --i) {
            int curr = 0;
            if (s[i] != '0')
                curr = stoi(s.substr(i, 2)) <= 26 ? pWays + ppWays : pWays;
            swap(ppWays, pWays);
            swap(pWays, curr);
            // even shorter:
            // swap(ppWays, pWays);
            // pWays = s[i] == '0'
            //             ? 0
            //             : stoi(s.substr(i, 2)) <= 26 ? pWays + ppWays : ppWays;
        }

        return pWays;
    }
};