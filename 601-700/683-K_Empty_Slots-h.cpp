// There is a garden with N slots. In each slot, there is a flower. The N
// flowers will bloom one by one in N days. In each day, there will be exactly
// one flower blooming and it will be in the status of blooming since then.

// Given an array flowers consists of number from 1 to N. Each number in the
// array represents the place where the flower will open in that day.

// For example, flowers[i] = x means that the unique flower that blooms at day i
// will be at position x, where i and x will be in the range from 1 to N.

// Also given an integer k, you need to output in which day there exists two
// flowers in the status of blooming, and also the number of flowers between
// them is k and these flowers are not blooming.

// If there isn't such day, output -1.

// Example 1:
// Input:
// flowers: [1,3,2]
// k: 1
// Output: 2
// Explanation: In the second day, the first and the third flower have become
// blooming.

// Example 2:
// Input:
// flowers: [1,2,3]
// k: 1
// Output: -1
// Note:
// The given array will be in the range [1, 20000].

// Bad description of question.
//
// flowers[day - 1] = pos, flower at 'pos' blooms at the 'day'
// build days[pos - 1] = day
// find days[L, ..., L + k, R] subarray,
// where days[L] or days[R] is the smallest in this subarray
class Solution {
  public:
    int kEmptySlots(vector<int> &flowers, int k) {
        int N = flowers.size();
        vector<int> days(N);
        for (int i = 0; i < N; ++i) {
            days[flowers[i] - 1] = i + 1;
        }

        int L = 0, R = k + 1, i = 1, ret = INT_MAX;
        while (R < N) {
            while (days[i] > days[L] && days[i] > days[R])
                ++i;
            if (i == R) {
                ret = min(ret, max(days[L], days[R]));
                L = R; // because above line may pick L or R
            } else {
                L = i;
            }
            i = L + 1;
            R = L + k + 1;
        }
        return ret == INT_MAX ? -1 : ret;
    }
};