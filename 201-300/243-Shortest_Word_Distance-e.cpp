// Given a list of words and two words word1 and word2, return the shortest
// distance between these two words in the list.

// Example:
// Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

// Input: word1 = “coding”, word2 = “practice”
// Output: 3
// Input: word1 = "makes", word2 = "coding"
// Output: 1
// Note:
// You may assume that word1 does not equal to word2, and word1 and word2 are
// both in the list.

class Solution {
  public:
    int shortestDistance(vector<string> &words, string word1, string word2) {
        int ret = words.size(), id1 = -1, id2 = -1;

        for (int i = 0; i < words.size(); ++i)
            if (words[i] == word1) {
                id1 = i;
                if (id2 != -1)
                    ret = min(ret, id1 - id2);
            } else if (words[i] == word2) {
                id2 = i;
                if (id1 != -1)
                    ret = min(ret, id2 - id1);
            }

        return ret;
    }
};