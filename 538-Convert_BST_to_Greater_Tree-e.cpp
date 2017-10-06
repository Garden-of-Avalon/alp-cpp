// Given a Binary Search Tree (BST), convert it to a Greater Tree such that
// every key of the original BST is changed to the original key plus sum of all
// keys greater than the original key in BST.
// Example:
// Input: The root of a Binary Search Tree like this:
//               5
//             /   \
//            2     13
// Output: The root of a Greater Tree like this:
//              18
//             /   \
//           20     13

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
    TreeNode *convertBST(TreeNode *root) {
        if (root) {
            if (root->right) {
                convertBST(root->right);
                TreeNode *temp = root->right;
                // Go to left most and update root val
                while (temp->left)
                    temp = temp->left;
                root->val += temp->val;
            }
            if (root->left) {
                TreeNode *temp = root->left;
                // Go to right most and add root val
                while (temp->right)
                    temp = temp->right;
                temp->val += root->val;
                convertBST(root->left);
            }
        }
        return root;
    }
};