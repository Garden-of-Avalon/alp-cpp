// Given a binary tree, find the length of the longest path where each node in
// the path has the same value. This path may or may not pass through the root.
// Note: The length of path between two nodes is represented by the number of
// edges between them.
// Example 1:
// Input:
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
// Output:
// 2
// Example 2:
// Input:
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
// Output:
// 2
// Note: The given binary tree has not more than 10000 nodes. The height of the
// tree is not more than 1000.

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
    // int ret = 0;
    int dfslen(TreeNode *n, int &ret) {
        if (!n)
            return 0;

        int l = dfslen(n->left, ret);
        int r = dfslen(n->right, ret);

        // length extend from current node
        int lext = 0, rext = 0;

        if (n->left && n->left->val == n->val)
            lext = l + 1;
        if (n->right && n->right->val == n->val)
            rext = r + 1;

        // update class-wise return value
        ret = max(ret, lext + rext);

        return max(lext, rext);
    }

  public:
    int longestUnivaluePath(TreeNode *root) {
        // faster than ret as private member
        int ret = 0;

        dfslen(root, ret);

        return ret;
    }
};