// Given an array of strings, group anagrams together.
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
// Return:
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
// Note: All inputs will be in lower-case.

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<string>> records;
        for (auto &&s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            // if(records.find(temp)!=end())
            records[temp].push_back(s);
        }
        vector<vector<string>> ret;
        for_each(records.begin(), records.end(),
                 [&](const pair<string, vector<string>> &p) {
                     ret.push_back(p.second);
                 });
        return ret;
    }
};