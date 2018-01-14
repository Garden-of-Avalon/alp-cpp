// Given a List of words, return the words that can be typed using letters of
// alphabet on only one row's of American keyboard like the image below.

// American keyboard

// Example 1:

// Input: ["Hello", "Alaska", "Dad", "Peace"]
// Output: ["Alaska", "Dad"]

// Note:

//     You may use one character in the keyboard more than once.
//     You may assume the input string will only contain letters of alphabet.

class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<unordered_set<char>> row;
        row.push_back({'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'});
        row.push_back({'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l'});
        row.push_back({'z', 'x', 'c', 'v', 'b', 'n', 'm'});

        vector<string> ret;

        for (auto &w : words) {
            if (w == "") {
                ret.push_back(w);
                continue;
            }

            bool can = true;
            int the_r; // the row

            for (int r = 0; r < 3; ++r)
                if (row[r].find(tolower(w[0])) != row[r].end()) {
                    the_r = r;
                    break;
                }

            for (int i = 1; i < w.size(); ++i)
                if (row[the_r].find(tolower(w[i])) == row[the_r].end()) {
                    can = false;
                    break;
                }

            if (can)
                ret.push_back(w);
        }

        return ret;
    }
};

// interesting method
// https://leetcode.com/problems/keyboard-row/discuss/97873
class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<string> res;

        for (auto str : words) {
            bool r1 = str.find_first_of("QWERTYUIOPqwertyuiop") == string::npos
                          ? false
                          : true;
            bool r2 = str.find_first_of("ASDFGHJKLasdfghjkl") == string::npos
                          ? false
                          : true;
            bool r3 = str.find_first_of("ZXCVBNMzxcvbnm") == string::npos
                          ? false
                          : true;

            if (r1 + r2 + r3 == 1)
                res.push_back(str);
        }

        return res;
    }
};

// another interesting one
// ref: https://leetcode.com/problems/keyboard-row/discuss/97872
class Solution {
  public:
    vector<string> findWords(vector<string> &words) {
        vector<unordered_set<char>> dict = {
            {'q', 'Q', 'w', 'W', 'e', 'E', 'r', 'R', 't', 'T',
             'y', 'Y', 'u', 'U', 'i', 'I', 'o', 'O', 'p', 'P'},
            {'a', 'A', 's', 'S', 'd', 'D', 'f', 'F', 'g', 'G', 'h', 'H', 'j',
             'J', 'k', 'K', 'l', 'L'},
            {'z', 'Z', 'x', 'X', 'c', 'C', 'v', 'V', 'b', 'B', 'n', 'N', 'm',
             'M'}};

        vector<string> res;

        for (auto &word : words) {
            vector<bool> d(3, true);

            for (auto &ch : word)
                for (int i = 0; i < 3; ++i)
                    if (d[i] && dict[i].find(ch) == dict[i].end())
                        d[i] = false;

            if (d[0] || d[1] || d[2])
                res.push_back(word);
        }

        return res;
    }
};