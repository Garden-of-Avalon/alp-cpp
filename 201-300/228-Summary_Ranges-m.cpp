//  Given a sorted integer array without duplicates, return the summary of its
//  ranges.

// Example 1:

// Input: [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]

// Example 2:

// Input: [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]

// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

class Solution {
  public:
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> ret;

        for (int i = 0; i < nums.size(); ++i) {
            stringstream tss; // temporary string stream
            int beg = nums[i];
            tss << beg;
            while (i + 1 < nums.size() && nums[i] + 1 == nums[i + 1])
                ++i;
            if (nums[i] != beg)
                tss << "->" << nums[i];
            ret.push_back(tss.str());
        }

        return ret;
    }
};