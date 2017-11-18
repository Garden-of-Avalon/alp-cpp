// Invert a binary tree.
//      4
//    /   \
//   2     7
//  / \   / \
// 1   3 6   9
// to
//      4
//    /   \
//   7     2
//  / \   / \
// 9   6 3   1
// Trivia:
// This problem was inspired by this original tweet by Max Howell:
//     Google: 90% of our engineers use the software you wrote (Homebrew), but
//     you can’t invert a binary tree on a whiteboard so fuck off.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// optimized version
class Solution {
  public:
    TreeNode *invertTree(TreeNode *root) {
        if (root) {
            invertTree(root->left);
            invertTree(root->right);
            std::swap(root->left, root->right);
        }
        return root;
    }
};

// ref 101
// class Solution {
//     void invertHelper(TreeNode *&l, TreeNode *&r) {
//         swap(l, r);
//         if (l)
//             invertHelper(l->left, l->right);
//         if (r)
//             invertHelper(r->left, r->right);
//     }

//   public:
//     TreeNode *invertTree(TreeNode *root) {
//         if (root)
//             invertHelper(root->left, root->right);
//         return root;
//     }
// };