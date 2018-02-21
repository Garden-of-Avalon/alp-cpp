// Given a non-empty integer array of size n, find the minimum number of moves
// required to make all array elements equal, where a move is incrementing n - 1
// elements by 1.

// Example:

// Input:
// [1,2,3]

// Output:
// 3

// Explanation:
// Only three moves are needed (remember each move increments two elements):

// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

// sang xin bing kuang
class Solution {
  public:
    int minMoves(vector<int> &nums) {
        return accumulate(nums.begin(), nums.end(), 0) -
               *min_element(nums.begin(), nums.end()) * nums.size();
    }
};

// avoid overflow, java ref
// public class Solution {
//     public int minMoves(int[] nums) {
//         int moves = 0, min = Integer.MAX_VALUE;
//         for (int i = 0; i < nums.length; i++)
//             min = Math.min(min, nums[i]);
//         for (int i = 0; i < nums.length; i++)
//             moves += nums[i] - min;
//         return moves;
//     }
// }

// ref:
// https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question

// let’s define sum as the sum of all the numbers, before any moves; minNum as
// the min number int the list; n is the length of the list;
// After, say m moves, we get all the numbers as x , and we will get the
// following equation

//  sum + m * (n - 1) = x * n

// and actually, x = minNum + m

// then

//  sum - minNum * n = m
