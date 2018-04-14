// Given a binary tree, return the inorder traversal of its nodes' values.

// For example:
// Given binary tree [1,null,2,3],

//    1
//     \
//      2
//     /
//    3

// return [1,3,2].

// Note: Recursive solution is trivial, could you do it iteratively?

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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        function<void(TreeNode *)> inorder = [&](TreeNode *r) {
            if (!r)
                return;

            inorder(r->left);
            ret.push_back(r->val);
            inorder(r->right);
        };
        inorder(root);
        return ret;
    }
};

// iterative
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        stack<TreeNode*> s;

        while(!s.empty() || root) 
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();

                ret.push_back(root->val);
                root = root->right;
            }

        return ret;
    }
};

// Morris inorder traversal - ref. 99