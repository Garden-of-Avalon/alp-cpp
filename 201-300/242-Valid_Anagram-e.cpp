// Given two strings s and t, write a function to determine if t is an anagram
// of s.
// For example,
// s = "anagram", t = "nagaram", return true.
// s = "rat", t = "car", return false.
// Note:
// You may assume the string contains only lowercase alphabets.
// Follow up:
// What if the inputs contain unicode characters? How would you adapt your
// solution to such case?

class Solution {
  public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, int> temp;
        // also can use int[26]
        for (int i = 0; i < s.size(); ++i) {
            ++temp[s[i]];
            --temp[t[i]];
        }

        for (auto &&item : temp)
            if (item.second)
                return false;

        return true;
    }
};