// Design and implement a TwoSum class. It should support the following
// operations: add and find.

// add - Add the number to an internal data structure.
// find - Find if there exists any pair of numbers which sum is equal to the
// value.

// Example 1:

// add(1); add(3); add(5);
// find(4) -> true
// find(7) -> false
// Example 2:

// add(3); add(1); add(2);
// find(3) -> true
// find(6) -> false

// add O(1), find O(n)
// can have high and low bounds to make search faster
class TwoSum {
    unordered_map<int, int> nums; // numbers and their counts

  public:
    /** Initialize your data structure here. */
    TwoSum() = default;

    /** Add the number to an internal data structure.. */
    void add(int number) { ++nums[number]; }

    /** Find if there exists any pair of numbers which sum is equal to the
     * value. */
    bool find(int value) {
        for (auto &&n_cnt : nums) {
            auto it = nums.find(value - n_cnt.first);
            if (it != nums.end() && (*it != n_cnt || n_cnt.second > 1))
                return true;
        }
        return false;
    }
};

// TLE, the case has too much add
// add O(n), find O(1)
class TwoSum {
    unordered_set<int> sums;
    unordered_set<int> nums;

  public:
    /** Initialize your data structure here. */
    TwoSum() = default;

    /** Add the number to an internal data structure.. */
    void add(int number) {
        if (nums.find(number) == nums.end()) {
            for (auto &&n : nums)
                sums.insert(n + number);
            nums.insert(number);
        } else
            sums.insert(number + number);
    }

    /** Find if there exists any pair of numbers which sum is equal to the
     * value. */
    bool find(int value) { return sums.find(value) != sums.end(); }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */