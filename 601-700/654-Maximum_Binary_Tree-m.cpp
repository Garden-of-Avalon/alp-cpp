//  Given an integer array with no duplicates. A maximum tree building on this
//  array is defined as follow:

//     The root is the maximum number in the array.
//     The left subtree is the maximum tree constructed from left part subarray
//     divided by the maximum number. The right subtree is the maximum tree
//     constructed from right part subarray divided by the maximum number.

// Construct the maximum tree by the given array and output the root node of
// this tree.

// Example 1:

// Input: [3,2,1,6,0,5]
// Output: return the tree root node representing the following tree:

//       6
//     /   \
//    3     5
//     \    /
//      2  0
//        \
//         1

// Note:

//     The size of the given array will be in the range [1,1000].

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
    // from b to e (not include index e)
    TreeNode *construct(vector<int> &nums, int b, int e) {
        if (b >= e)
            return NULL;

        int max_i =
            max_element(nums.begin() + b, nums.begin() + e) - nums.begin();

        TreeNode *ret = new TreeNode(nums[max_i]);

        ret->left = construct(nums, b, max_i);
        ret->right = construct(nums, max_i + 1, e);

        return ret;
    }

  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return construct(nums, 0, nums.size());
    }
};

class Solution {
  public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        // left root path
        // store left root in reverse order
        stack<TreeNode *> lrp;
        nums.push_back(INT_MAX);
        for (auto &n : nums) {
            TreeNode *node = new TreeNode(n), *prevTop = nullptr;
            while (!lrp.empty() && lrp.top()->val <= n) {
                lrp.top()->right = prevTop;
                prevTop = lrp.top();
                lrp.pop();
            }
            node->left = prevTop;
            lrp.push(node);
        }
        nums.pop_back();
        return lrp.top()->left;
    }
};

// Analysis
// method 1: O(nlogn), somehow like sorting
// method 2: O(n)
// The result is not a totally sorted data structure (e.g. BST),
// to convert it to a sorted array/list, we need to compare child nodes.
// So optimization from O(nlogn) to O(n) is possible.