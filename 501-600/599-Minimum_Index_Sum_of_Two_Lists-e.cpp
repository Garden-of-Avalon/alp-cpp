// Suppose Andy and Doris want to choose a restaurant for dinner, and they both
// have a list of favorite restaurants represented by strings.

// You need to help them find out their common interest with the least list
// index sum. If there is a choice tie between answers, output all of them with
// no order requirement. You could assume there always exists an answer.

// Example 1:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
// Output: ["Shogun"]
// Explanation: The only restaurant they both like is "Shogun".

// Example 2:
// Input:
// ["Shogun", "Tapioca Express", "Burger King", "KFC"]
// ["KFC", "Shogun", "Burger King"]
// Output: ["Shogun"]
// Explanation: The restaurant they both like and have the least index sum is
// "Shogun" with index sum 1 (0+1).

// Note:
// The length of both lists will be in the range of [1, 1000].
// The length of strings in both lists will be in the range of [1, 30].
// The index is starting from 0 to the list length minus 1.
// No duplicates in both lists.

class Solution {
  public:
    vector<string> findRestaurant(vector<string> &list1,
                                  vector<string> &list2) {
        if (list1.size() > list2.size())
            return findRestaurant(list2, list1);

        unordered_map<string, int> res_idx;
        for (int i = 0; i < list1.size(); ++i)
            res_idx.emplace(list1[i], i);

        int min_idx_sum = numeric_limits<int>::max();
        vector<string> ret;

        for (int i = 0; i < list2.size(); ++i)
            if (res_idx.count(list2[i])) {
                int temp_sum = i + res_idx[list2[i]];
                if (temp_sum == min_idx_sum)
                    ret.push_back(list2[i]);
                else if (temp_sum < min_idx_sum) {
                    ret = {list2[i]};
                    min_idx_sum = temp_sum;
                }
            }

        return ret;
    }
};