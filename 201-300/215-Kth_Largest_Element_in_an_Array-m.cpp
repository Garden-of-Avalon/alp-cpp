// Find the kth largest element in an unsorted array. Note that it is the kth
// largest element in the sorted order, not the kth distinct element.

// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ array's length.

// Credits:
// Special thanks to @mithmatt for adding this problem and creating all test
// cases.

class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // smaller at top

        for (auto &n : nums)
            if (pq.size() < k)
                pq.push(n);
            else if (n > pq.top()) {
                pq.pop();
                pq.push(n);
            }

        return pq.top();
    }
};