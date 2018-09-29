// Given a binary tree, return the postorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [3,2,1]
// Follow up: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ret;

        stack<TreeNode *> s;
        TreeNode *last = NULL;

        while (!s.empty() || root) {
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                auto *peek = s.top();

                if (!peek->right || peek->right == last) {
                    ret.push_back(peek->val);
                    last = peek;
                    s.pop();
                } else
                    root = peek->right;
            }
        }

        return ret;
    }
};