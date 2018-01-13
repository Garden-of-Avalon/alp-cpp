//  Given a string which contains only lowercase letters, remove duplicate
//  letters so that every letter appear once and only once. You must make sure
//  your result is the smallest in lexicographical order among all possible
//  results.

// Example:

// Given "bcabc"
// Return "abc"

// Given "cbacdcbc"
// Return "acdb"

// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test
// cases.

// key idea is keep the original relative position
// at the same time, make the result the smallest in lexicographical order
class Solution {
  public:
    string removeDuplicateLetters(string s) {
        vector<int> cnt(256, 0);
        vector<bool> visited(256, false);

        for (auto &c : s)
            ++cnt[c];

        string ret = "0";

        for (auto &c : s) {
            --cnt[c];

            if (visited[c])
                continue;

            // if we have ret.back later, and c is smaller than ret.back
            // remove ret.back
            while (cnt[ret.back()] && c < ret.back()) {
                visited[ret.back()] = false;
                ret.pop_back();
            }

            ret += c;
            visited[c] = true;
        }

        return ret.substr(1);
    }
};