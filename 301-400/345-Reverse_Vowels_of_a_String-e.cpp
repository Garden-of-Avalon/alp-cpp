// Write a function that takes a string as input and reverse only the vowels of
// a string.

// Example 1:
// Given s = "hello", return "holle".

// Example 2:
// Given s = "leetcode", return "leotcede".

// Note:
// The vowels does not include the letter "y".

class Solution {
  public:
    string reverseVowels(string s) {
        vector<size_t> vpos; // vow positions
        unordered_set<char> vow = {'A', 'a', 'E', 'e', 'I',
                                   'i', 'O', 'o', 'U', 'u'};
        for (size_t i = 0; i < s.size(); ++i)
            if (vow.find(s[i]) != vow.end())
                vpos.push_back(i);

        int i = 0, j = vpos.size() - 1;

        while (i < j)
            swap(s[vpos[i++]], s[vpos[j--]]);

        return s;
    }
};