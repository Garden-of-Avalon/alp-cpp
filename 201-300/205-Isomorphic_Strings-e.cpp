// Given two strings s and t, determine if they are isomorphic.

// Two strings are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while
// preserving the order of characters. No two characters may map to the same
// character but a character may map to itself.

// For example,
// Given "egg", "add", return true.

// Given "foo", "bar", return false.

// Given "paper", "title", return true.

// Note:
// You may assume both s and t have the same length.

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
        vector<char> stot(128), ttos(128); // 128 basic ASCII
        for (int i = 0; i < s.size(); ++i)
            if (!stot[s[i]] && !ttos[t[i]]) {
                stot[s[i]] = t[i];
                ttos[t[i]] = s[i];
            } else if (s[i] != ttos[t[i]])
                return false;
        return true;
    }
};