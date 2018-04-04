// Given a complete binary tree, count the number of nodes.

// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is
// completely filled, and all nodes in the last level are as far left as
// possible. It can have between 1 and 2h nodes inclusive at the last level h.

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
  public:
    int countNodes(TreeNode *root) {
        if (!root)
            return 0;

        int left_d = 0, right_d = 0;
        TreeNode *l_node = root->left, *r_node = root->right;
        while (l_node) {
            ++left_d;
            l_node = l_node->left;
        }
        while (r_node) {
            ++right_d;
            r_node = r_node->right;
        }

        if (left_d == right_d)
            return pow(2, left_d + 1) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
