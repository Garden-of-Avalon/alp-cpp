// There is a new alien language which uses the latin alphabet. However, the
// order among letters are unknown to you. You receive a list of non-empty words
// from the dictionary, where words are sorted lexicographically by the rules of
// this new language. Derive the order of letters in this language.

// Example 1:

// Input:
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]

// Output: "wertf"
// Example 2:

// Input:
// [
//   "z",
//   "x"
// ]

// Output: "zx"
// Example 3:

// Input:
// [
//   "z",
//   "x",
//   "z"
// ]

// Output: ""

// Explanation: The order is invalid, so return "".
// Note:

// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the
// given dictionary. If the order is invalid, return an empty string. There may
// be multiple valid order of letters, return any one of them is fine.

class Solution {
  public:
    string alienOrder(vector<string> &words) {
        // after['a'] is  the set of chars ordered later than 'a'
        unordered_map<char, unordered_set<char>> after;

        // precnt['a'] is the (min) prefix length of 'a' in result
        // 'xyza', precnt['a'] == 3
        unordered_map<char, int> precnt;

        for (auto &&w : words)
            for (auto &&c : w)
                precnt.emplace(c, 0);

        for (int i = 0; i < words.size() - 1; ++i) {
            int j = 0, sz = words[i].size(); // safe
            while (j < sz && words[i][j] == words[i + 1][j])
                ++j;
            if (j == sz)
                continue;

            if (after.count(words[i + 1][j]) &&
                after[words[i + 1][j]].count(words[i][j]))
                return ""; // invalid

            if (after[words[i][j]].insert(words[i + 1][j]).second)
                ++precnt[words[i + 1][j]];
        }

        queue<char> q;
        string ret;

        for (auto &l : precnt)
            if (l.second == 0)
                q.push(l.first);

        while (!q.empty()) {
            char c = q.front();
            q.pop();
            ret += c;
            if (after.count(c))
                for (auto &cc : after[c])
                    if (--precnt[cc] == 0)
                        q.push(cc);
        }

        if (ret.size() != precnt.size())
            return "";

        return ret;
    }
};
