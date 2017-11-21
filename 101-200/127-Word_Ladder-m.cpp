//  Given two words (beginWord and endWord), and a dictionary's word list, find
//  the length of shortest transformation sequence from beginWord to endWord,
//  such that:
//     Only one letter can be changed at a time.
//     Each transformed word must exist in the word list. Note that beginWord is
//     not a transformed word.
// For example,
// Given:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log","cog"]
// As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.
// Note:
//     Return 0 if there is no such transformation sequence.
//     All words have the same length.
//     All words contain only lowercase alphabetic characters.
//     You may assume no duplicates in the word list.
//     You may assume beginWord and endWord are non-empty and are not the same.
// UPDATE (2017/1/20):
// The wordList parameter had been changed to a list of strings (instead of a
// set of strings). Please reload the code definition to get the latest changes.

class Solution {
  public:
    int ladderLength(string beginWord, string endWord,
                     vector<string> &wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return 0;

        unordered_set<string> head, tail, *ptrhead, *ptrtail;
        head.insert(beginWord);
        tail.insert(endWord);

        int ret = 1;
        while (!head.empty() && !tail.empty()) {
            ++ret;

            ptrhead = &head;
            ptrtail = &tail;
            if (head.size() > tail.size())
                swap(ptrhead, ptrtail);

            decltype(head) temp; // practice of decltype
            for (auto it = ptrhead->begin(); it != ptrhead->end(); ++it) {
                string middle = *it;
                // here we cannot use string &middle;
                // All iterators in an unordered_set have const access to the
                // elements (even those whose type is not prefixed with const_):
                // Elements can be inserted or removed, but not modified while
                // in the container.
                for (int i = 0; i < middle.size(); ++i) {
                    char mtemp = middle[i];
                    for (char ch = 'a'; ch < 'z'; ++ch) {
                        middle[i] = ch;
                        if (ptrtail->find(middle) != ptrtail->end())
                            return ret;
                        if (dict.find(middle) != dict.end()) {
                            temp.insert(middle);
                            dict.erase(middle);
                        }
                    }
                    middle[i] = mtemp;
                }
            }

            *ptrhead = temp;
        }

        return 0;
    }
};