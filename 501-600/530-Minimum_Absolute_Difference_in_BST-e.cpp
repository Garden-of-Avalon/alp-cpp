// Given a binary search tree with non-negative values, find the minimum
// absolute difference between values of any two nodes.

// Example:

// Input:

//    1
//     \
//      3
//     /
//    2

// Output:
// 1

// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1
// (or between 2 and 3). Note: There are at least two nodes in this BST.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// another in-order traversal
class Solution {
    TreeNode *prev = nullptr;
    int ret = numeric_limits<int>::max();

    void inorder(TreeNode *root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev)
            ret = min(ret, root->val - prev->val);
        prev = root;

        inorder(root->right);
    }

  public:
    int getMinimumDifference(TreeNode *root) {
        inorder(root);
        return ret;
    }
};

// iterative
class Solution {
  public:
    int getMinimumDifference(TreeNode *root) {
        TreeNode *prev = nullptr;
        int ret = numeric_limits<int>::max();

        stack<TreeNode *> st;

        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();

                if (prev)
                    ret = min(ret, root->val - prev->val);
                prev = root;

                root = root->right;
            }
        }

        return ret;
    }
};