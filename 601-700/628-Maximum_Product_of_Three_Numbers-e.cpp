// Given an integer array, find three numbers whose product is maximum and
// output the maximum product.

// Example 1:

// Input: [1,2,3]
// Output: 6

// Example 2:

// Input: [1,2,3,4]
// Output: 24

// Note:

//     The length of the given array will be in range [3,104] and all elements
//     are in the range [-1000, 1000]. Multiplication of any three numbers in
//     the input won't exceed the range of 32-bit signed integer.

class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        int cnt_p = 0, cnt_n = 0;
        int *first_0_ptr = nullptr;
        for (auto &&n : nums)
            if (n > 0)
                ++cnt_p;
            else if (n < 0)
                ++cnt_n;
            else if (!first_0_ptr)
                first_0_ptr = &n;

        int cand1 = INT_MIN, cand2 = INT_MIN, cand3 = INT_MIN, cand4 = INT_MIN;

        //  positives
        if (cnt_p >= 3)
            cand1 = accumulate(nums.rbegin(), nums.rbegin() + 3, 1,
                               std::multiplies<int>());
        if (cnt_n >= 2 && cnt_p >= 1)
            cand2 = nums[0] * nums[1] * nums.back();

        // negative
        if (cnt_n >= 3 && !first_0_ptr)
            cand3 = nums[cnt_n - 1] * nums[cnt_n - 2] * nums[cnt_n - 3];

        // zero
        if (first_0_ptr)
            cand4 = 0;

        return max({cand1, cand2, cand3, cand4});
    }
};

// ref answer, UGLY!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        vector<int> maxes(3, INT_MIN), mins(2, INT_MAX);

        for (auto &&n : nums) {
            if (n > maxes[0]) {
                maxes[2] = maxes[1];
                maxes[1] = maxes[0];
                maxes[0] = n;
            } else if (n > maxes[1]) {
                maxes[2] = maxes[1];
                maxes[1] = n;
            } else if (n > maxes[2])
                maxes[2] = n;

            if (n < mins[0]) {
                mins[1] = mins[0];
                mins[0] = n;
            } else if (n < mins[1])
                mins[1] = n;
        }

        return max(maxes[0] * maxes[1] * maxes[2],
                   mins[0] * mins[1] * maxes[0]);
    }
};

// somehow elegant
class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        multiset<int> maxes, mins;

        for (auto &&n : nums) {
            maxes.insert(n);
            if (maxes.size() > 3)
                maxes.erase(maxes.begin());

            mins.insert(n);
            if (mins.size() > 2)
                mins.erase(std::prev(mins.end()));
        }

        auto prod = [](const multiset<int> &m) {
            return accumulate(m.begin(), m.end(), 1, multiplies<int>());
        };

        return max(prod(maxes), *maxes.rbegin() * prod(mins));
    }
};

//  use priority queue
class Solution {
  public:
    int maximumProduct(vector<int> &nums) {
        priority_queue<int, vector<int>, greater<int>> maxes; // min at top
        priority_queue<int> mins;                             // max at top

        for (auto &&n : nums) {
            maxes.push(n);
            if (maxes.size() > 3)
                maxes.pop();

            mins.push(n);
            if (mins.size() > 2)
                mins.pop();
        }

        auto prod = [](auto &m) {
            pair<int, int> ret = make_pair(1, 1);
            while (!m.empty()) {
                ret.first *= m.top();
                ret.second = m.top();
                m.pop();
            }
            return ret;
        };

        auto maxprod = prod(maxes); // product, last value in queue
        return max(maxprod.first, maxprod.second * prod(mins).first);
    }
};