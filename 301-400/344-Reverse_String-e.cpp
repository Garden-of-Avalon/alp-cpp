// Write a function that takes a string as input and returns the string
// reversed.
// Example:
// Given s = "hello", return "olleh".

class Solution {
  public:
    string reverseString(string s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            std::swap(s[i++], s[j--]);
        return s;
    }
};

// MLE for very long string
// class Solution {
// public:
//     string reverseString(string s) {
//         if (s.size() < 2)
//             return s;
//         return s.back() + reverseString(s.substr(0, s.size() - 1));
//     }
// };