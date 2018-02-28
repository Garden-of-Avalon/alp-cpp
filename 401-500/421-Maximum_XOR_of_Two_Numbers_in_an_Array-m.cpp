// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 ≤ ai < 231.

// Find the maximum result of ai XOR aj, where 0 ≤ i, j < n.

// Could you do this in O(n) runtime?

// Example:

// Input: [3, 10, 5, 25, 2, 8]

// Output: 28

// Explanation: The maximum result is 5 ^ 25 = 28.

// method 1: follow the highest ranked method in LC discussion
class Solution {
  public:
    int findMaximumXOR(vector<int> &nums) {
        int ret = 0, mask = 0;

        // outer loop can be considered as O(1)
        for (int i = 31; i >= 0; --i) {
            // mask == 10000..., 11000..., 11100...
            mask |= (1 << i);
            unordered_set<int> prefix;
            for (auto &&n : nums)
                prefix.insert(n & mask);

            // decide ith bit in final ret, for each i
            int temp = ret | (1 << i);
            for (auto &&pr : prefix)
                if (prefix.find(temp ^ pr) != prefix.end()) {
                    ret = temp; // pr ^ the_value == temp
                    break;
                }
        }

        return ret;
    }
};

// method 2: trie TODO