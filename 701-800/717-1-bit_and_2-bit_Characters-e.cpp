// We have two special characters. The first character can be represented by one
// bit 0. The second character can be represented by two bits (10 or 11).

// Now given a string represented by several bits. Return whether the last
// character must be a one-bit character or not. The given string will always
// end with a zero.

// Example 1:

// Input:
// bits = [1, 0, 0]
// Output: True
// Explanation:
// The only way to decode it is two-bit character and one-bit character. So the
// last character is one-bit character.

// Example 2:

// Input:
// bits = [1, 1, 1, 0]
// Output: False
// Explanation:
// The only way to decode it is two-bit character and two-bit character. So the
// last character is NOT one-bit character.

// Note:
// 1 <= len(bits) <= 1000.
// bits[i] is always 0 or 1.

// Note: don't think too much

class Solution {
  public:
    bool isOneBitCharacter(vector<int> &bits) {
        int i = 0;
        while (i < bits.size() - 1) {
            if (bits[i])
                ++i;
            ++i;
        }
        return i == bit.size() - 1;
    }
};

// greedy ?
class Solution {
  public:
    bool isOneBitCharacter(vector<int> &bits) {
        auto second_last_zero = find(next(bits.rbegin()), bits.rend(), 0);
        // count even 1s, example: ....011110
        return distance(prev(second_last_zero), bits.rbegin()) % 2 == 0;
    }
};