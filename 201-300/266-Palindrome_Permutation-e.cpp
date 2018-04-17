// Given a string, determine if a permutation of the string could form a
// palindrome.

// For example,
// "code" -> False, "aab" -> True, "carerac" -> True.

class Solution {
  public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> m;
        for (auto &&c : s)
            ++m[c];
        bool p_ret = true; // possible return value
        for (auto &&x : m)
            if (x.second % 2)
                if (p_ret)
                    p_ret = false;
                else
                    return false;
        return true;
    }
};

// cleaner
class Solution {
  public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (auto &&c : s)
            b.flip(c);
        return b.count() < 2;
    }
};
