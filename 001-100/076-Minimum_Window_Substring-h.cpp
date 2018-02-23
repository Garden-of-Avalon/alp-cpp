//  Given a string S and a string T, find the minimum window in S which will
//  contain all the characters in T in complexity O(n).

// For example,
// S = "ADOBECODEBANC"
// T = "ABC"

// Minimum window is "BANC".

// Note:
// If there is no such window in S that covers all characters in T, return the
// empty string "".

// If there are multiple such windows, you are guaranteed that there will always
// be only one unique minimum window in S.

class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmap;

        for (auto &&c : t)
            ++tmap[c];

        int l = 0, r = 0, cnt = t.size();
        int prev_begin = 0, d = INT_MAX;
        while (r < s.size()) {
            if (tmap[s[r++]]-- > 0)
                --cnt;
            while (cnt == 0) {
                if (r - l < d)
                    d = r - (prev_begin = l);

                if (tmap[s[l++]]++ == 0)
                    ++cnt;
            }
        }

        return d == INT_MAX ? "" : s.substr(prev_begin, d);
    }
};