//  Given a binary tree, determine if it is a valid binary search tree (BST).

// Assume a BST is defined as follows:

//     The left subtree of a node contains only nodes with keys less than the
//     node's key. The right subtree of a node contains only nodes with keys
//     greater than the node's key. Both the left and right subtrees must also
//     be binary search trees.

// Example 1:

//     2
//    / \
//   1   3

// Binary tree [2,1,3], return true.

// Example 2:

//     1
//    / \
//   2   3

// Binary tree [1,2,3], return false.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// method 1
class Solution {
    int small(TreeNode *root) {
        while (root->left)
            root = root->left;
        return root->val;
    }

    int big(TreeNode *root) {
        while (root->right)
            root = root->right;
        return root->val;
    }

  public:
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;

        return (root->left ? big(root->left) < root->val : true) &&
               (root->right ? root->val < small(root->right) : true) &&
               isValidBST(root->left) && isValidBST(root->right);
    }
};

// method 2: in-order traversal
class Solution {
    TreeNode *prev = nullptr;

  public:
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;

        // bool b1 = isValidBST(root->left);
        // // visit root
        // bool b2 = prev ? prev->val < root->val : true;
        // prev = root;
        // bool b3 = isValidBST(root->right);
        // return b1 && b2 && b3;

        return isValidBST(root->left) &&
               (prev ? prev->val < root->val : true) && (prev = root) &&
               isValidBST(root->right);
    }
};

// method 3: in-order traversal - iterative
class Solution {
    TreeNode *prev = nullptr;

  public:
    bool isValidBST(TreeNode *root) {
        stack<TreeNode *> s;
        while (!s.empty() || root)
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();

                // visit root
                if (!(prev ? prev->val < root->val : true))
                    return false;
                prev = root;

                root = root->right;
            }

        return true;
    }
};