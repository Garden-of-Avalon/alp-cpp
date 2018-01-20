//  Given an array with n objects colored red, white or blue, sort them so that
//  objects of the same color are adjacent, with the colors in the order red,
//  white and blue.

// Here, we will use the integers 0, 1, and 2 to represent the color red, white,
// and blue respectively.

// Note:
// You are not suppose to use the library's sort function for this problem.

// click to show follow up.

// Follow up:
// A rather straight forward solution is a two-pass algorithm using counting
// sort. First, iterate the array counting number of 0's, 1's, and 2's, then
// overwrite array with total number of 0's, then 1's and followed by 2's.

// Could you come up with an one-pass algorithm using only constant space?

class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int red = 0, blue = nums.size() - 1;

        auto passred = [&]() {
            while (red < nums.size() && nums[red] == 0)
                ++red;
        };

        auto passblue = [&]() {
            while (blue >= 0 && nums[blue] == 2)
                --blue;
        };

        int i = 0;

        while (i <= blue) {
            passred();  // now red is first non-zero element
            passblue(); // now blue is first non-two element (reverse direction)
            if (i < red) // let i go faster if possible
                i = red;

            if (nums[i] == 0 && i > red) {
                swap(nums[i++], nums[red++]);
                if (nums[i - 1] == 2)
                    --i; // handle blue in next loop
            } else if (nums[i] == 2 && i <= blue) {
                swap(nums[i++], nums[blue--]);
                if (nums[i - 1] == 0)
                    --i; // handle red in next loop
            } else
                ++i; // case n == 1
        }

        return;
    }
};

// even simplified
class Solution {
  public:
    void sortColors(vector<int> &nums) {
        int red = 0, blue = nums.size() - 1;

        int i = 0;
        while (i <= blue) {
            if (nums[i] == 0 && i > red)
                swap(nums[i], nums[red++]);
            else if (nums[i] == 2 && i < blue)
                swap(nums[i], nums[blue--]);
            else
                ++i;
        }

        return;
    }
};

// for k colors, bisise counting sort (should be the best solution)
// in-place(?) swap method
void sortColors2(vector<int> &colors, int left, int right, int colorFrom,
                 int colorTo) {
    if (colorFrom == colorTo || left >= right)
        return;

    int colorMid = (colorFrom + colorTo) / 2;
    int l = left, r = right;
    while (l <= r) {
        while (l <= r && colors[l] <= colorMid)
            l++;
        while (l <= r && colors[r] > colorMid)
            r--;
        if (l <= r)
            swap(colors[l++], colors[r--]);
    }

    sortColors2(colors, left, r, colorFrom, colorMid);
    sortColors2(colors, l, right, colorMid + 1, colorTo);
}