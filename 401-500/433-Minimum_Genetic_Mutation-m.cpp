// A gene string can be represented by an 8-character long string, with choices
// from "A", "C", "G", "T".
// Suppose we need to investigate about a mutation (mutation from "start" to
// "end"), where ONE mutation is defined as ONE single character changed in the
// gene string.
// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
// Also, there is a given gene "bank", which records all the valid gene
// mutations. A gene must be in the bank to make it a valid gene string.
// Now, given 3 things - start, end, bank, your task is to determine what is the
// minimum number of mutations needed to mutate from "start" to "end". If there
// is no such a mutation, return -1.
// Note:
//     Starting point is assumed to be valid, so it might not be included in the
//     bank. If multiple mutations are needed, all mutations during in the
//     sequence must be valid. You may assume start and end string is not the
//     same.
// Example 1:
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]
// return: 1
// Example 2:
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
// return: 2
// Example 3:
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
// return: 3

// ref 127
class Solution {
  public:
    int minMutation(string start, string end, vector<string> &bank) {
        unordered_set<string> dict(bank.begin(), bank.end());
        if (dict.find(end) == dict.end())
            return -1;

        unordered_set<string> head, tail, *ptrhead, *ptrtail;
        head.insert(start);
        tail.insert(end);

        int ret = 0;
        string ATGC("ATGC"); // used for iteration
        while (!head.empty() && !tail.empty()) {
            ++ret;

            ptrhead = &head;
            ptrtail = &tail;
            if (head.size() > tail.size())
                swap(ptrhead, ptrtail);

            decltype(head) temp; // practice of decltype
            for (auto it = ptrhead->begin(); it != ptrhead->end(); ++it) {
                string middle(*it);
                for (int i = 0; i < middle.size(); ++i) {
                    char midtemp = middle[i];
                    for (auto &ch : ATGC) {
                        middle[i] = ch;
                        if (ptrtail->find(middle) != ptrtail->end())
                            return ret;
                        if (dict.find(middle) != dict.end()) {
                            temp.insert(middle);
                            dict.erase(middle);
                        }
                    }
                    middle[i] = midtemp;
                }
            }

            *ptrhead = temp;
        }

        return -1;
    }
};