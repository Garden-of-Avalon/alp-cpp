// Given an unsorted array, find the maximum difference between the successive
// elements in its sorted form.

// Try to solve it in linear time/space.

// Return 0 if the array contains less than 2 elements.

// You may assume all elements in the array are non-negative integers and fit in
// the 32-bit signed integer range.

// Credits:
// Special thanks to @porker2008 for adding this problem and creating all test
// cases.

class Solution {
    struct bucket {
        bool used = false;
        // or numeric_limits<int>::max();
        int minval = INT_MAX;
        int maxval = INT_MIN;
    };

  public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;

        auto minmax_it = minmax_element(nums.begin(), nums.end());
        int min_n = *minmax_it.first, max_n = *minmax_it.second;

        int bucket_size =
            max(1, (max_n - min_n) / (static_cast<int>(nums.size()) - 1));
        int bucket_num = (max_n - min_n) / bucket_size + 1; // important
        vector<bucket> buckets(bucket_num);

        for (auto &n : nums) {
            int bucket_i = (n - min_n) / bucket_size;
            buckets[bucket_i].used = true;
            buckets[bucket_i].minval = min(n, buckets[bucket_i].minval);
            buckets[bucket_i].maxval = max(n, buckets[bucket_i].maxval);
        }

        int prev_max = min_n, maxgap = 0;
        for (auto &b : buckets) {
            if (!b.used)
                continue;

            maxgap = max(maxgap, b.minval - prev_max);
            prev_max = b.maxval;
        }

        return maxgap;
    }
};

// TODO radix sort