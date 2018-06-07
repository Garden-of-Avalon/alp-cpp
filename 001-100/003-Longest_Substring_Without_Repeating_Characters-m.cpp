// Given a string, find the length of the longest substring without repeating
// characters.
// Examples:
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the
// answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        vector<int> idx(128, -1); // last appear index of a char

        int ret = 0, len = 0;
        for (int i = 0; i < s.size(); ++i) {
            len = min(len + 1, i - idx[s[i]]);
            ret = max(ret, len);
            idx[s[i]] = i;
        }

        return ret;
    }
};

// the optimized sliding window algorithm
// C++ standard library <algorithm>, <map>, etc.
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int result = 0, sz = s.size();
        map<char, int> mymap;
        for (int i = 0, j = 0; j < sz; ++j) {
            if (mymap.find(s[j]) != mymap.end()) {
                i = max(i, mymap.at(s[j]) + 1);
            }
            // save or update both char and index
            mymap[s[j]] = j;
            result = max(j - i + 1, result);
        }
        return result;
    }
};
