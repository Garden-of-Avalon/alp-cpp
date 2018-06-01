// Given a string which consists of lowercase or uppercase letters, find the
// length of the longest palindromes that can be built with those letters.

// This is case sensitive, for example "Aa" is not considered a palindrome here.

// Note:
// Assume the length of given string will not exceed 1,010.

// Example:

// Input:
// "abccccdd"

// Output:
// 7

// Explanation:
// One longest palindrome that can be built is "dccaccd", whose length is 7.

// or use vector<int>(128)
class Solution {
  public:
    int longestPalindrome(string s) {
        unordered_map<char, int> cnts;
        for (auto &&c : s)
            ++cnts[c];

        bool odd_exist = false;
        int ret = 0;

        for (auto &&ch_cnt : cnts)
            if (ch_cnt.second % 2 == 0)
                ret += ch_cnt.second;
            else {
                ret += ch_cnt.second - 1;
                odd_exist = true;
            }

        return ret + odd_exist;
    }
};