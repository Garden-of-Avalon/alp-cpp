// Given an array where elements are sorted in ascending order, convert it to a
// height balanced BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode *helper(vector<int> &nums, int l, int r) {
        if (l < 0 || r > nums.size() - 1 || l > r)
            return NULL;

        int mid = (l + r) / 2;

        TreeNode *root = new TreeNode(nums[mid]);

        root->left = helper(nums, l, mid - 1);
        root->right = helper(nums, mid + 1, r);

        return root;
    }

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};

// Note

// For [1, 2, 3, 4, 5]
// [3,1,4,null,2,null,5] and [3,2,5,1,null,4] are both correct
// to get latter one
// just let mid = (l + r + 1) / 2

// Example: l = 1, r = 2
// if use mid = (l + r) / 2
// 1 will be root and 2 will be root->right
// if use mid = (l + r + 1) / 2
// 2 will be root and 1 will be root->left
