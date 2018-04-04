//  Given a binary tree, flatten it to a linked list in-place.

// For example,
// Given

//          1
//         / \
//        2   5
//       / \   \
//      3   4   6

// The flattened tree should look like:

//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6

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
    // return last node
    TreeNode *helper(TreeNode *root) {
        if (!root)
            return NULL;
        if (!root->left && !root->right)
            return root;

        TreeNode *l_last = helper(root->left), *r_last = helper(root->right);

        if (l_last) {
            l_last->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }

        if (r_last)
            return r_last;
        else
            return l_last;
    }

  public:
    void flatten(TreeNode *root) { helper(root); }
};

// short Java post order ref
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/discuss/36977/My-short-post-order-traversal-Java-solution-for-share
// private TreeNode prev = null;
// public void flatten(TreeNode root) {
//     if (root == null)
//         return;
//     flatten(root.right);
//     flatten(root.left);
//     root.right = prev;
//     root.left = null;
//     prev = root;
// }