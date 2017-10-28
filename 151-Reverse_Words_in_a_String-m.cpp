// Given an input string, reverse the string word by word.
// For example,
// Given s = "the sky is blue",
// return "blue is sky the".
// Update (2015-02-12):
// For C programmers: Try to solve it in-place in O(1) space.
// click to show clarification.
// Clarification:
//     What constitutes a word?
//     A sequence of non-space characters constitutes a word.
//     Could the input string contain leading or trailing spaces?
//     Yes. However, your reversed string should not contain leading or trailing
//     spaces.
//     How about multiple spaces between two words?
//     Reduce them to a single space in the reversed string.

class Solution {
  public:
    void reverseWords(string &s) {
        int i, j;

        // remove spaces at head and tail
        i = 0;
        j = s.size() - 1;
        while (i < s.size() && s[i] == ' ')
            ++i;
        while (j >= 0 && s[j] == ' ')
            --j;
        s = j >= i ? s.substr(i, j - i + 1) : "";

        // remove continuous spaces
        i = 0;
        while (i < s.size() && s[i] != ' ')
            ++i;
        do {
            j = ++i; // second space
            while (j < s.size() && s[j] == ' ')
                ++j;
            while (j < s.size() && s[j] != ' ')
                swap(s[i++], s[j++]);
            // now s[i] == ' ' or i == s.size()
        } while (j < s.size());
        s = s.substr(0, i);

        // reverse sentence
        i = 0;
        j = s.size() - 1;
        while (i < j)
            swap(s[i++], s[j--]);

        // reverse every word
        int k = 0;
        while (k < s.size()) {
            i = k;
            while (i < s.size() && s[i] == ' ')
                ++i;
            j = i;
            while (j < s.size() && s[j] != ' ')
                ++j;
            k = j;
            --j;
            while (i < j)
                swap(s[i++], s[j--]);
        }

        // finish
    }
};