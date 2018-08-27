// Given a non-empty list of words, return the k most frequent elements.

// Your answer should be sorted by frequency from highest to lowest. If two
// words have the same frequency, then the word with the lower alphabetical
// order comes first.

// Example 1:
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is",
// "is"], k = 4 Output: ["the", "is", "sunny", "day"] Explanation: "the", "is",
// "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.

// Follow up:
// Try to solve it in O(n log k) time and O(n) extra space.

class Solution {
  public:
    vector<string> topKFrequent(vector<string> &words, int k) {
        unordered_map<string, int> wordMap;

        // O(n)
        for_each(words.begin(), words.end(), [&](auto &w) { ++wordMap[w]; });

        static constexpr auto compCnt = [](auto &a, auto &b) {
            if (a.second == b.second)
                return a.first <
                       b.first; // higher alphabetical at beginning to pop
            return a.second > b.second; // smaller cnt at beginning to pop
        };

        // O(nlogk)
        priority_queue<pair<string, int>, vector<pair<string, int>>,
                       decltype(compCnt)>
            pq(compCnt);
        for (auto &wCnt : wordMap) {
            pq.push(wCnt);
            if (pq.size() > k)
                pq.pop();
        }

        // O(k)
        vector<string> ret(k);
        while (!pq.empty()) {
            ret[--k] = pq.top().first;
            pq.pop();
        }

        return ret;
    }
};