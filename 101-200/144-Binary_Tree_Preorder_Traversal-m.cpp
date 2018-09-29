// Given a binary tree, return the preorder traversal of its nodes' values.

// Example:

// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3

// Output: [1,2,3]
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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return {};

        stack<TreeNode *> s;
        s.push(root);

        vector<int> ret;

        while (!s.empty()) {
            auto p = s.top();
            s.pop();
            ret.push_back(p->val);

            if (p->right)
                s.push(p->right);
            if (p->left)
                s.push(p->left);
        }

        return ret;
    }
};