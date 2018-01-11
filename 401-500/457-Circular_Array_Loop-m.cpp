//  You are given an array of positive and negative integers. If a number n at
//  an index is positive, then move forward n steps. Conversely, if it's
//  negative (-n), move backward n steps. Assume the first element of the array
//  is forward next to the last element, and the last element is backward next
//  to the first element. Determine if there is a loop in this array. A loop
//  starts and ends at a particular index with more than 1 element along the
//  loop. The loop must be "forward" or "backward'.

// Example 1: Given the array [2, -1, 1, 2, 2], there is a loop, from index 0 ->
// 2 -> 3 -> 0.

// Example 2: Given the array [-1, 2], there is no loop.

// Note: The given array is guaranteed to contain no element "0".

// Can you do it in O(n) time complexity and O(1) space complexity?

class Solution {
  public:
    bool circularArrayLoop(vector<int> &nums) {
        int sz = nums.size();

        if (sz < 2)
            return false;

        auto move = [&](int i) {
            (i += nums[i]) %= sz;
            if (i < 0)
                i += sz;
            return i;
        };

        for (int i = 0; i < sz; ++i) {
            if (!nums[i])
                continue;

            int slow = i, fast = i, cnt = 0;
            do {
                slow = move(slow);
                fast = move(move(fast));
                ++cnt;
            } while (slow != fast &&
                     (nums[i] > 0 && nums[slow] > 0 && nums[fast] > 0 ||
                      nums[i] < 0 && nums[slow] < 0 && nums[fast] < 0));
            // avoid overflow
            // } while (slow != fast && nums[i] * nums[slow] > 0 &&
            //          nums[i] * nums[fast] > 0);

            if (slow == fast && slow != move(slow))
                return true;

            slow = i;
            while (cnt-- > 0) {
                int temp = move(slow);
                nums[slow] = 0;
                slow = temp;
            }
        }

        return false;
    }
};