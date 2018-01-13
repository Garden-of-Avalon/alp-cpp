//  Given a list of unique words, find all pairs of distinct indices (i, j) in
//  the given list, so that the concatenation of the two words, i.e. words[i] +
//  words[j] is a palindrome.

// Example 1:
// Given words = ["bat", "tab", "cat"]
// Return [[0, 1], [1, 0]]
// The palindromes are ["battab", "tabbat"]

// Example 2:
// Given words = ["abcd", "dcba", "lls", "s", "sssll"]
// Return [[0, 1], [1, 0], [3, 2], [2, 4]]
// The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]

// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test
// cases.

class Solution {
    bool ispal(string &s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }

  public:
    vector<vector<int>> palindromePairs(vector<string> &words) {
        // create a reverse dictionary
        unordered_map<string, int> dict;
        for (int i = 0; i < words.size(); ++i) {
            string w = words[i];
            reverse(w.begin(), w.end());
            dict[w] = i;
        }

        vector<vector<int>> ret;
        for (int i = 0; i < words.size(); ++i)
            for (int j = 0; j < words[i].size(); ++j) {
                string left = words[i].substr(0, j), right = words[i].substr(j);

                if (ispal(right) && dict.find(left) != dict.end() &&
                    dict[left] != i) {
                    ret.push_back({i, dict[left]});
                    if (left.empty()) // {self, ""}
                        ret.push_back({dict[left], i});
                }

                if (ispal(left) && dict.find(right) != dict.end() &&
                    dict[right] != i)
                    ret.push_back({dict[right], i});
            }

        return ret;
    }
};