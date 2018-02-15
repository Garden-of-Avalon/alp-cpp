//  Implement next permutation, which rearranges numbers into the
//  lexicographically next greater permutation of numbers.

// If such arrangement is not possible, it must rearrange it as the lowest
// possible order (ie, sorted in ascending order).

// The replacement must be in-place, do not allocate extra memory.

// Here are some examples. Inputs are in the left-hand column and its
// corresponding outputs are in the right-hand column.

// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() < 2)
            return;

        auto it = nums.rbegin();

        while (++it != nums.rend() && *it >= *(it - 1))
            ;

        if (it != nums.rend()) {
            // find it2: first element from rbegin, which is larger than *it
            auto it2 = nums.rbegin();

            while ((it2 + 1) != it && *it2 <= *it)
                ++it2;

            swap(*it, *it2);
        }

        reverse(nums.rbegin(), it);

        return;
    }
};

class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        next_permutation(nums.begin(), nums.end());
        return;
    }
};