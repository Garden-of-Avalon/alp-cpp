// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as a binary tree
// in which the depth of the two subtrees of every node never differ by more
// than 1.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// "depth of a tree" is misleading
// we only have height of a node, height of a tree, and depth of a node
class Solution {
    int height(TreeNode *root) {
        if (!root)
            return 0;

        int l = height(root->left);
        int r = height(root->right);

        if (l < 0 || r < 0 || abs(l - r) > 1)
            return -1; // just a number to mark

        return 1 + max(l, r);
    }

  public:
    bool isBalanced(TreeNode *root) { return height(root) != -1; }
};