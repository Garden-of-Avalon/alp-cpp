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

// quick select
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        int l = 0, r = nums.size() - 1;

        while (true) {
            // partition
            int storei = l;
            // select pivot value
            swap(nums[l + rand() % (r - l + 1)], nums[r]);
            for (int i = l; i < r; ++i)
                if (nums[i] < nums[r])
                    swap(nums[storei++], nums[i]);
            swap(nums[storei], nums[r]); // nums[storei] is the pivot now

            if (storei == nums.size() - k)
                return nums[storei];
            else if (storei < nums.size() - k)
                l = storei + 1;
            else
                r = storei - 1;
        }

        // since k is always valid, function should have returned
    }
};