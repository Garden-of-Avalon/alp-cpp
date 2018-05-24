// Given a non-empty array of integers, return the third maximum number in this
// array. If it does not exist, return the maximum number. The time complexity
// must be in O(n).

// Example 1:
// Input: [3, 2, 1]

// Output: 1

// Explanation: The third maximum is 1.
// Example 2:
// Input: [1, 2]

// Output: 2

// Explanation: The third maximum does not exist, so the maximum (2) is returned
// instead. Example 3: Input: [2, 2, 3, 1]

// Output: 1

// Explanation: Note that the third maximum here means the third maximum
// distinct number. Both numbers with value 2 are both considered as second
// maximum.

class Solution {
  public:
    int thirdMax(vector<int> &nums) {
        long long fir = numeric_limits<long long>::lowest(),
                  sec = fir,
                  thi = fir;

        for (auto &&n : nums) {
            if (n == fir || n == sec || n == thi)
                continue;

            if (n > fir) {
                thi = sec;
                sec = fir;
                fir = n;
            } else if (n > sec) {
                thi = sec;
                sec = n;
            } else if (n > thi) {
                thi = n;
            }
            // cout << fir << ' ' << sec << ' ' << thi << endl;
        }

        return thi == numeric_limits<long long>::lowest() ? fir : thi;
    }
};