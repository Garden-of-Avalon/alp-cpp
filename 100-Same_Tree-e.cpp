// Given two binary trees, write a function to check if they are equal or not.
// Two binary trees are considered equal if they are structurally identical and
// the nodes have the same value.

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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q)
            return true;

        // preorder traverse
        stack<TreeNode *> ptemp;
        stack<TreeNode *> qtemp;
        while (p && q || !ptemp.empty() && !qtemp.empty()) {
            if (p && q && p->val != q->val || p && !q || !p && q)
                return false;

            if (p && q) {
                ptemp.push(p->right);
                p = p->left;
                qtemp.push(q->right);
                q = q->left;
            } else {
                p = ptemp.top();
                ptemp.pop();
                q = qtemp.top();
                qtemp.pop();
            }
        }

        // p == q == null
        return p == q;
    }
};

// recursive
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p || !q)
            return p == q;
        return p->val == q->val && isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};