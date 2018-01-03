// A password is considered strong if below conditions are all met:

//     It has at least 6 characters and at most 20 characters.
//     It must contain at least one lowercase letter, at least one uppercase
//     letter, and at least one digit. It must NOT contain three repeating
//     characters in a row ("...aaa..." is weak, but "...aa...a..." is strong,
//     assuming other conditions are met).

// Write a function strongPasswordChecker(s), that takes a string s as input,
// and return the MINIMUM change required to make s a strong password. If s is
// already strong, return 0.

// Insertion, deletion or replace of any one character are all considered as one
// change.

// follow https://leetcode.com/problems/strong-password-checker/discuss/91008
class Solution {
  public:
    int strongPasswordChecker(string s) {
        int missing_type = 3;
        if (any_of(s.begin(), s.end(), [](char &c) { return islower(c); }))
            --missing_type;
        if (any_of(s.begin(), s.end(), [](char &c) { return isupper(c); }))
            --missing_type;
        if (any_of(s.begin(), s.end(), [](char &c) { return isdigit(c); }))
            --missing_type;

        int sz = s.size();
        int repls = 0;                 // replacements due to repeating
        int rem_zero = 0, rem_one = 0; // times of remainder 0 or 1
        for (int i = 2; i < sz;)
            if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
                int repeat_len = 2;
                while (i < sz && s[i] == s[i - 1]) {
                    ++repeat_len;
                    ++i;
                }
                repls += repeat_len / 3;
                if (repeat_len % 3 == 0)
                    ++rem_zero;
                else if (repeat_len % 3 == 1)
                    ++rem_one;
            } else
                ++i;

        if (sz < 6)
            return max(missing_type, 6 - sz);
        else if (sz <= 20)
            return max(missing_type, repls);
        else {
            int dels = sz - 20;

            // For any repeating sequences with len % 3 == 0, we can reduce one
            // replacement by deleting one character. For any repeating
            // sequences with len % 3 == 1, we can reduce one replacement by
            // deleting two character. For the remaining sequences, we can
            // reduce every replacement by deleting three character.
            repls -= min(dels, rem_zero);
            repls -= min(max(dels - rem_zero, 0), rem_one * 2) / 2;
            repls -= max(dels - rem_zero - 2 * rem_one, 0) / 3;

            return dels + max(missing_type, repls);
        }

        // previous code will cover the cases of return 0.
    }
};