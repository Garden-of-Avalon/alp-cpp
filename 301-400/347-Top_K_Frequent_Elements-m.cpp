//  Given a non-empty array of integers, return the k most frequent elements.

// For example,
// Given [1,1,1,2,2,3] and k = 2, return [1,2].

// Note:

//     You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
//     Your algorithm's time complexity must be better than O(n log n), where n
//     is the array's size.

class Solution {
  public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> freqmap;
        for (auto &n : nums)
            ++freqmap[n];

        // index is frequency-1, value is corespponding integers
        vector<vector<int>> freqvecs(nums.size());
        for (auto &p : freqmap)
            freqvecs[p.second - 1].push_back(p.first);

        vector<int> ret;
        for (auto rit = freqvecs.rbegin(); rit != freqvecs.rend(); ++rit) {
            copy(rit->begin(), rit->end(), back_inserter(ret));
            if (ret.size() >= k)
                break;
        }

        return ret;
    }
};