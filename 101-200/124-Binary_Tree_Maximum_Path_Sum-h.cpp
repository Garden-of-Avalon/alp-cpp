//  Given a binary tree, find the maximum path sum.

// For this problem, a path is defined as any sequence of nodes from some
// starting node to any node in the tree along the parent-child connections. The
// path must contain at least one node and does not need to go through the root.

// For example:
// Given the below binary tree,

//        1
//       / \
//      2   3

// Return 6.

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
    unordered_map<TreeNode *, bool> used;

    int max_val = INT_MIN;

    int oneside(TreeNode *root) {
        if (!root)
            return INT_MIN;

        int lsum = max(0, oneside(root->left)),
            rsum = max(0, oneside(root->right));

        max_val = max(max_val, lsum + rsum + root->val);

        return root->val + max(lsum, rsum);
    }

  public:
    int maxPathSum(TreeNode *root) {
        oneside(root);
        return max_val;
    }
};