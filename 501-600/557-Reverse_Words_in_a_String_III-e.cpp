// Given a string, you need to reverse the order of characters in each word
// within a sentence while still preserving whitespace and initial word order.

// Example 1:

// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Note: In the string, each word is separated by single space and there will
// not be any extra space in the string.

class Solution {
    void revRange(string &s, int i, int j) {
        while (i < j)
            swap(s[i++], s[j--]);
    }

  public:
    string reverseWords(string s) {
        int start = 0;
        size_t pos; // it can convert to int when we call revRange
        while ((pos = s.find(' ', start)) != string::npos) {
            revRange(s, start, pos - 1);
            start = pos + 1;
        }

        revRange(s, start, s.size() - 1); // for last word

        return s;
    }
};

// simplified
class Solution {
  public:
    string reverseWords(string s) {
        int start = 0, t;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == ' ') {
                t = i - 1;
                while (start < t)
                    swap(s[start++], s[t--]);
                start = i + 1;
            }

        t = s.size() - 1;
        while (start < t)
            swap(s[start++], s[t--]); // for last word

        return s;
    }
};