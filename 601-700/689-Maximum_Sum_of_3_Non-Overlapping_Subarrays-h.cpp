// In a given array nums of positive integers, find three non-overlapping
// subarrays with maximum sum.

// Each subarray will be of size k, and we want to maximize the sum of all 3*k
// entries.

// Return the result as a list of indices representing the starting position of
// each interval (0-indexed). If there are multiple answers, return the
// lexicographically smallest one.

// Example:
// Input: [1,2,1,2,6,7,5,1], 2

// Output: [0, 3, 5]

// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting
// indices [0, 3, 5]. We could have also taken [2, 1], but an answer of [1, 3,
// 5] would be lexicographically larger.

// Note:
// nums.length will be between 1 and 20000.
// nums[i] will be between 1 and 65535.
// k will be between 1 and floor(nums.length / 3).

// Analysis:
// 1. find all sums S, e.g., when k = 3, S[0] is the sum of index 0, 1, 2
// 2. need to find 3 indexes a, b, c to make sum of S[a], S[b], S[c] largest
// 3. when we fix a, loop of b and c will cost O(n^2); similar for fixing c
// 4. when we fix b, loop of a and c both will cost O(n)
// 5. when we move b, the prefix of current b and previous b are very similar
//    just one more element
// 6. might use DP, have a prefix largest sum array for a, and postfix for c
//    in this case, 'loop' of a and c will cost O(1)
// 7. for further optimization (save space), prefix array is not necessary
//    and the postfix array can be a stack, only push new largest value's index
//    (largest value is from the end of S)
// better greedy/DP: O(1) space
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108238/Python-o(n)-time-o(1)-space.-Greedy-solution.
// more generic DP: for M cuts
// https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/discuss/108239/Java-DP-Generic-Solution-for-M-subarrays

// ref: 123

// greedy, O(1) space
class Solution {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k) {
        vector<int> index = {0, k, 2 * k}; // current window
        vector<int> currSums(3);           // current 3 sums of k
        vector<int> best(3);               // best sum of 1, 2, 3 sequences
        vector<vector<int>> ret(3, index); // related to 3 bests above

        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < k; ++j)
                currSums[i] += nums[index[i] + j];

        best[0] = currSums[0];
        best[1] = best[0] + currSums[1];
        best[2] = best[1] + currSums[2];

        while (index[2] + k < nums.size()) {
            for (int i = 0; i < 3; ++i) {
                currSums[i] += nums[index[i] + k] - nums[index[i]];

                if ((i ? best[i - 1] : 0) + currSums[i] > best[i]) {
                    best[i] = (i ? best[i - 1] : 0) + currSums[i];
                    if (i)
                        ret[i] = ret[i - 1];
                    ret[i][i] = index[i] + 1;
                }
            }

            for_each(index.begin(), index.end(), [](auto &i) { ++i; });
        }

        return ret[2];
    }
};