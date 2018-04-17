//  Given a non-empty binary search tree and a target value, find the value in
//  the BST that is closest to the target.

// Note:

//     Given target value is a floating point.
//     You are guaranteed to have only one unique value in the BST that is
//     closest to the target.

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
    int closestValue(TreeNode *root, double target) {
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        while (!s.empty() || root)
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();

                // visit root
                if (target == root->val)
                    return target;
                if (target < root->val)
                    if (!prev)
                        return root->val;
                    else
                        return target - prev->val > root->val - target
                                   ? root->val
                                   : prev->val;

                prev = root;
                root = root->right;
            }

        return prev->val; // right most
    }
};