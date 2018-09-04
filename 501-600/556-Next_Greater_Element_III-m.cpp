// Given a positive 32-bit integer n, you need to find the smallest 32-bit
// integer which has exactly the same digits existing in the integer n and is
// greater in value than n. If no such positive 32-bit integer exists, you need
// to return -1.

// Example 1:

// Input: 12
// Output: 21

// Example 2:

// Input: 21
// Output: -1

class Solution {
  public:
    int nextGreaterElement(int n) {
        string nstr = to_string(n);
        next_permutation(nstr.begin(), nstr.end());
        long long ret = stoll(nstr);

        return ret <= INT_MAX && ret > n ? ret : -1;
    }
};

// ref: 031
class Solution {
    void nextPermutation(string &s) {
        if (s.size() < 2)
            return;

        // find first decrease (from right to left)
        auto rit = s.rbegin();
        while (++rit != s.rend() && *rit >= *(rit - 1))
            ;
        
        if (rit != s.rend()) {
            // find first which is lager than *rit
            auto rit2 = s.rbegin();
            while(rit2 + 1 != rit && *rit2 <= *rit)
                ++rit2;

            swap(*rit, *rit2);
        }

        reverse(s.rbegin(), rit);
    }

  public:
    int nextGreaterElement(int n) {
        string nstr = to_string(n);
        nextPermutation(nstr);
        long long ret = stoll(nstr);

        return ret <= INT_MAX && ret > n ? ret : -1;
    }
};