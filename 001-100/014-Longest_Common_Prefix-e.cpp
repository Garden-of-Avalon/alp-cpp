// Write a function to find the longest common prefix string amongst an array of
// strings.

// small optimization with lambda
class Solution {
  public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
            return "";

        int shortest_len = INT_MAX;
        for (auto &&s : strs)
            shortest_len = min(shortest_len, static_cast<int>(s.size()));

        for (int i = 0; i < shortest_len; ++i)
            for (auto &&s : strs)
                if (s[i] != strs[0][i])
                    return strs[0].substr(0, i);

        return strs[0].substr(0, shortest_len);
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