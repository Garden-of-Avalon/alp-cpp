// Given a binary search tree (BST) with duplicates, find all the mode(s) (the
// most frequently occurred element) in the given BST.

// Assume a BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than or equal
// to the node's key. The right subtree of a node contains only nodes with keys
// greater than or equal to the node's key. Both the left and right subtrees
// must also be binary search trees. For example: Given BST [1,null,2,2],
//    1
//     \
//      2
//     /
//    2
// return [2].

// Note: If a tree has more than one mode, you can return them in any order.

// Follow up: Could you do that without using any extra space? (Assume that the
// implicit stack space incurred due to recursion does not count).

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// in order traverse
// for ture O(1), refer to 099 and TaoLu DFS - Morris in-order traverse
class Solution {
    vector<int> ret;
    int max_cnt = 1, curr_cnt = 0, prev = INT_MIN;

    void inorder(TreeNode *root) {
        if (!root)
            return;

        inorder(root->left);

        if (root->val == prev) {
            ++curr_cnt;
            if (curr_cnt > max_cnt) {
                ret[0] = root->val;
                ret.resize(1); // truncate
                max_cnt = curr_cnt;
            } else if (curr_cnt == max_cnt)
                ret.push_back(root->val);
        } else {
            curr_cnt = 1;
            if (max_cnt == 1)
                ret.push_back(root->val);
            prev = root->val;
        }

        inorder(root->right);
    }

  public:
    vector<int> findMode(TreeNode *root) {
        inorder(root);
        return ret;
    }
};