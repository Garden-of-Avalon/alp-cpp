//  Given n balloons, indexed from 0 to n-1. Each balloon is painted with a
//  number on it represented by array nums. You are asked to burst all the
//  balloons. If the you burst balloon i you will get nums[left] * nums[i] *
//  nums[right] coins. Here left and right are adjacent indices of i. After the
//  burst, the left and right then becomes adjacent.

// Find the maximum coins you can collect by bursting the balloons wisely.

// Note:
// (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you
// can not burst them. (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100

// Example:

// Given [3, 1, 5, 8]

// Return 167

//     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

// ref:
// https://leetcode.com/problems/burst-balloons/discuss/76230/C++-dp-detailed-explanation
// for each subinterval, in the innermost for loop, find which balloon to burst
// LAST that will give us the most coins for that subinterval.
// dp[left][right] is the maximum coins we can get from left to right. note when
// left > right, it is 0
//    1···················1    (len = 7)
//     |     |
//   left  right
//    1···················1
//            |     |
//          left  right
//    1···················1
//                 |     |
//               left  right
// for the example [3, 1, 5, 8], the dp matrix is updated like this
// 0    0    0    0    0    0
// 0    3    0    0    0    0
// 0    0    15   0    0    0
// 0    0    0    40   0    0
// 0    0    0    0    40   0
// 0    0    0    0    0    0
// then
// 0    0    0    0    0    0
// 0    3    30   0    0    0
// 0    0    15   135  0    0
// 0    0    0    40   48   0
// 0    0    0    0    40   0
// 0    0    0    0    0    0
// at last
// 0    0    0    0    0    0
// 0    3    30   159  167  0
// 0    0    15   135  159  0
// 0    0    0    40   48   0
// 0    0    0    0    40   0
// 0    0    0    0    0    0
class Solution {
  public:
    int maxCoins(vector<int> &nums) {
        int n = nums.size();

        vector<int> ns{1};
        copy(nums.begin(), nums.end(), back_inserter(ns));
        ns.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));

        for (int len = 1; len <= n; ++len)
            for (int left = 1, right = len; left <= n - len + 1;
                 ++left, ++right)
                for (int k = left; k <= right; ++k)
                    dp[left][right] =
                        max(dp[left][right],
                            ns[left - 1] * ns[k] * ns[right + 1] +
                                dp[left][k - 1] + dp[k + 1][right]);
        return dp[1][n];
    }
};

// WRONG, we do need to scan every element from left to right
// [2,1,8,9,7] when left == 2, right == 4, the following code is not correct
// Yu Shu's optimize
// analysis: we don't need to scan the whole length (left to right)
// but just update by
// max(dp[i][j - 1] + last_element_prod, first_element_prod + dp[i + 1][j])
// class Solution {
//     void printdp(auto &dp) {
//         for (auto &&row : dp) {
//             for (auto &&col : row)
//                 cout << col << ' ';
//             cout << '\n';
//         }
//         cout << '\n';
//     }

//   public:
//     int maxCoins(vector<int> &nums) {
//         int n = nums.size();
//         vector<int> ns{1};
//         copy(nums.begin(), nums.end(), back_inserter(ns));
//         ns.push_back(1);

//         vector<vector<int>> dp(n + 2, vector<int>(n + 2));

//         for (int len = 1; len <= n; ++len) {
//             for (int left = 1, right = len; left <= n - len + 1;
//                  ++left, ++right) {
//                 int right_single = dp[left][right - 1] +
//                                    ns[left - 1] * ns[right] * ns[right + 1];
//                 int left_single = ns[left - 1] * ns[left] * ns[right + 1] +
//                                   dp[left + 1][right];
//                 dp[left][right] = max(left_single, right_single);
//             }
//             printdp(dp);
//         }
//         return dp[1][n];
//     }
// };

//// far away wrong........................
//
// class Solution {
//     void safeupdate(auto &index_prod, auto &prod_index, int index, int
//     update) {
//         int val = index_prod[index];

//         decltype(prod_index.begin()) del_it;
//         vector<pair<int, int>> temp;
//         while ((del_it = prod_index.find(val))->second != index) {
//             temp.push_back(*del_it);
//             prod_index.erase(del_it);
//         }
//         prod_index.erase(del_it);
//         for (auto &&t : temp)
//             prod_index.emplace(t);

//         prod_index.emplace(update, index);
//         index_prod.emplace(index, update);
//     }

//   public:
//     int maxCoins(vector<int> &nums) {
//         int n = nums.size();
//         if (n == 0)
//             return 0;
//         if (n == 1)
//             return nums[0];

//         int ret = 0;

//         multimap<int, int> prod_index;
//         map<int, int> index_prod;

//         for (int i = 0; i < n; ++i) {
//             int prod = (i > 0 ? nums[i - 1] : 1) * nums[i] *
//                        (i + 1 == n ? nums[i + 1] : 1);
//             prod_index.emplace(prod, i);
//             index_prod.emplace(i, prod);
//         }

//         while (!index_prod.empty()) {
//             // erase the burst balloon
//             auto burst = prev(prod_index.end()); // the one to burst
//             int curr_index = burst->second, curr_val = burst->first;
//             prod_index.erase(burst);
//             index_prod.erase(curr_index);

//             // update ret
//             ret += curr_val;
//             cout << curr_val << ' ' << ret << endl;

//             if (index_prod.empty())
//                 break;

//             auto next_it = index_prod.upper_bound(curr_index);
//             int prev_index, prevprev_index, next_index, nextnext_index;
//             if (next_it == index_prod.begin()) {
//                 prev_index = -1;
//                 prevprev_index = -1;
//             } else if (next_it == index_prod.end()) {
//                 next_index = n;
//                 nextnext_index = n;
//             } else {
//                 auto prev_it = prev(next_it);
//                 prev_index = prev_it->first;
//                 prevprev_index =
//                     prev_it == index_prod.begin() ? -1 :
//                     prev(prev_it)->first;

//                 next_index = next_it->first;
//                 auto nextnext_it = next(next_it);
//                 nextnext_index =
//                     nextnext_it == index_prod.end() ? n : nextnext_it->first;
//             }

//             int prev_update =
//                 (prevprev_index == -1 ? 1 : nums[prevprev_index]) *
//                 (prev_index == -1 ? 1 : nums[prev_index]) *
//                 (next_index == n ? 1 : nums[next_index]);
//             int next_update = (prev_index == -1 ? 1 : nums[prev_index]) *
//                               (next_index == n ? 1 : nums[next_index]) *
//                               (nextnext_index == n ? 1 :
//                               nums[nextnext_index]);
//             // safe update prev
//             if (prev_index != -1)
//                 safeupdate(index_prod, prod_index, prev_index, prev_update);
//             if (next_index != n)
//                 safeupdate(index_prod, prod_index, next_index, next_update);
//         }

//         return ret;
//     }
// };