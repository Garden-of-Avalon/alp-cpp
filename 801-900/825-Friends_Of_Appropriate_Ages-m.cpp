// Some people will make friend requests. The list of their ages is given and
// ages[i] is the age of the ith person.

// Person A will NOT friend request person B (B != A) if any of the following
// conditions are true:

// age[B] <= 0.5 * age[A] + 7
// age[B] > age[A]
// age[B] > 100 && age[A] < 100
// Otherwise, A will friend request B.

// Note that if A requests B, B does not necessarily request A.  Also, people
// will not friend request themselves.

// How many total friend requests are made?

// Example 1:

// Input: [16,16]
// Output: 2
// Explanation: 2 people friend request each other.
// Example 2:

// Input: [16,17,18]
// Output: 2
// Explanation: Friend requests are made 17 -> 16, 18 -> 17.
// Example 3:

// Input: [20,30,100,110,120]
// Output:
// Explanation: Friend requests are made 110 -> 100, 120 -> 110, 120 -> 100.

// Notes:

// 1 <= ages.length <= 20000.
// 1 <= ages[i] <= 120.

class Solution {
  public:
    int numFriendRequests(vector<int> &ages) {
        sort(ages.begin(), ages.end());

        int ret = 0;
        auto it = ages.begin();
        while (it != ages.end()) {
            // 0.5A + 7 < B <= A
            auto left = upper_bound(ages.begin(), ages.end(), 0.5 * (*it) + 7);
            auto right = upper_bound(ages.begin(), ages.end(), *it);
            if (right - left <= 1) {
                ++it;
                continue;
            }

            int add = right - left - 1;
            ret += (right - it) * add;
            it = right;
        }

        return ret;
    }
};

// counting sort usage
class Solution {
  public:
    int numFriendRequests(vector<int> &ages) {
        array<int, 121> agecnt = {};
        for (auto &&a : ages)
            ++agecnt[a];

        int ret = 0;
        for (int i = 1; i < 121; ++i)
            if (agecnt[i]) {
                // 0.5A + 7 < B <= A
                int left = 0.5 * i + 7 + 1;
                int right = i + 1;
                if (left < right) {
                    int add = 0;
                    for (int j = left; j < i; ++j)
                        add += agecnt[j];
                    add += agecnt[i] - 1; // not contain self

                    ret += agecnt[i] * add;
                }
            }

        return ret;
    }
};

// further optimization, use accumulated sum
class Solution {
  public:
    int numFriendRequests(vector<int> &ages) {
        array<int, 121> agecnt = {};
        for (auto &&a : ages)
            ++agecnt[a];

        int ret = 0;
        for (int i = 1; i < 121; agecnt[i] += agecnt[i - 1], ++i)
            if (agecnt[i]) {
                // 0.5A + 7 < B <= A
                int left = 0.5 * i + 7;
                if (left < i) {
                    // begin to i - 1 are accumulated sum
                    int add = agecnt[i - 1] - agecnt[left];
                    // not contain self
                    add += agecnt[i] - 1;

                    ret += agecnt[i] * add;
                }
            }

        return ret;
    }
};