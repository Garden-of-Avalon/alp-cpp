// A strobogrammatic number is a number that looks the same when rotated 180
// degrees (looked at upside down).

// Write a function to determine if a number is strobogrammatic. The number is
// represented as a string.

// Example 1:

// Input:  "69"
// Output: true
// Example 2:

// Input:  "88"
// Output: true
// Example 3:

// Input:  "962"
// Output: false

class Solution {
  public:
    bool isStrobogrammatic(string num) {
        int l = 0, r = num.size() - 1;
        unordered_map<char, char> m = {
            {'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};

        while (l <= r)
            if (m[num[l++]] != num[r--])
                return false;

        return true;
    }
};