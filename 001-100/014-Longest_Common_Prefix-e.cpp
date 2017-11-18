// Write a function to find the longest common prefix string amongst an array of
// strings.

// small optimization with lambda
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";
        sort(strs.begin(), strs.end(),
             [](string &a, string &b) { return a.size() < b.size(); });
        int shortest_length = strs[0].size();
        for (int i = 0; i < shortest_length; ++i)
            for (auto &str : strs)
                if (str[i] != strs[0][i])
                    return strs[0].substr(0, i);
        return strs[0]; // the shortest string is empty string
    }
};

// original answer
// class Solution {
//   public:
//     string longestCommonPrefix(vector<string> &strs) {
//         if (strs.empty())
//             return "";
//         int shortest_length = strs[0].size();
//         for (auto str : strs) {
//             if (str.size() < shortest_length)
//                 shortest_length = str.size();
//         }
//         string temp;
//         for (auto i = 0; i < shortest_length; ++i) {
//             for (auto str : strs) {
//                 if (str[i] != strs[0][i])
//                     return temp;
//             }
//             temp += strs[0][i];
//         }
//         return temp; // cover the case of shortest_length == 0
//     }
// };