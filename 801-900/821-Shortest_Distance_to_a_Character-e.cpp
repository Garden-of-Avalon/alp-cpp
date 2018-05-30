// Given a string S and a character C, return an array of integers representing
// the shortest distance from the character C in the string.

// Example 1:

// Input: S = "loveleetcode", C = 'e'
// Output: [3, 2, 1, 0, 1, 0, 0, 1, 2, 2, 1, 0]

// Note:

// S string length is in [1, 10000].
// C is a single character, and guaranteed to be in string S.
// All letters in S and C are lowercase.

class Solution {
  public:
    vector<int> shortestToChar(string S, char C) {
        int sz = S.size(), dist = 10000; // distance value upper bound
        vector<int> ret(sz, dist);

        auto update = [&](const int &i) {
            if (S[i] == C)
                dist = 0;
            ret[i] = min(dist++, ret[i]);
        };

        for (int i = 0; i < sz; ++i)
            update(i);
        for (int i = sz - 1; i >= 0; --i)
            update(i);

        return ret;
    }
};