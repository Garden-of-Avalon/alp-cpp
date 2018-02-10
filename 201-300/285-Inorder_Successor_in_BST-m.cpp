//  Given a binary search tree and a node in it, find the in-order successor of
//  that node in the BST.

// Note: If the given node has no in-order successor in the tree, return null.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// actually do not need to traversal all
class Solution {
  public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        // in-order traverse
        stack<TreeNode *> s;

        while (!s.empty() || root)
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();

                // visit root
                if (root->val > p->val)
                    return root;

                root = root->right;
            }

        return NULL;
    }
};

// better
class Solution {
  public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *succ = NULL;
        while (root)
            if (p->val < root->val) {
                succ = root;
                root = root->left;
            } else
                root = root->right;
        return succ;
    }
};