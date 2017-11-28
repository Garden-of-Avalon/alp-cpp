//  Given a collection of numbers that might contain duplicates, return all
//  possible unique permutations.
// For example,
// [1,1,2] have the following unique permutations:
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]

// Recursive Backtracking
class Solution {
    void genPermu(vector<int> nums, int start, vector<vector<int>> &result) {
        if (start == nums.size() - 1)
            result.push_back(nums);
        else {
            for (int i = start; i < nums.size(); ++i) {
                if (nums[i] == nums[start] && i != start)
                    continue;
                swap(nums[start], nums[i]);
                genPermu(nums, start + 1, result);
                // do not do swap(nums[start], nums[i]);
            }
        }
    }

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        // necessary to make line 7 work right
        // line 7: if (nums[i] == nums[start] && i != start)
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        // here we pass a copy into genPermu
        genPermu(nums, 0, result);

        return result;
    }
};

// closer to 046
class Solution {
    void genPermu(vector<int> &nums, int start, vector<vector<int>> &result) {
        if (start == nums.size() - 1)
            result.push_back(nums);
        else {
            unordered_set<int> temp;
            // here set has better performance
            for (int i = start; i < nums.size(); ++i)
                if (temp.insert(nums[i]).second) {
                    swap(nums[start], nums[i]);
                    genPermu(nums, start + 1, result);
                    swap(nums[start], nums[i]);
                }
        }
    }

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        vector<vector<int>> result;
        genPermu(nums, 0, result);
        return result;
    }
};