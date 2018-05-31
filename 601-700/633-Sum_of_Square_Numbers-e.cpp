// Given a non-negative integer c, your task is to decide whether there're two
// integers a and b such that a2 + b2 = c.

// Example 1:
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5
// Example 2:
// Input: 3
// Output: False

// method similar to "two sum"
class Solution {
  public:
    bool judgeSquareSum(int c) {
        int sqroot = sqrt(c);
        unordered_set<int> squares;

        for (int i = 0; i <= sqroot; ++i) {
            int temp_square = i * i;
            squares.insert(temp_square);
            if (squares.find(c - temp_square) != squares.end())
                return true;
        }

        return false;
    }
};

// faster
class Solution {
  public:
    bool judgeSquareSum(int c) {
        int l = 0, r = sqrt(c);

        while (l <= r) {
            long long temp = l * l + r * r;
            if (temp == c)
                return true;
            else if (temp < c)
                ++l;
            else
                --r;
        }

        return false;
    }
};