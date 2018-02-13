// Find the sum of all left leaves in a given binary tree.

// Example:

//     3
//    / \
//   9  20
//     /  \
//    15   7

// There are two left leaves in the binary tree, with values 9 and 15
// respectively. Return 24.

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
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root)
            return 0;

        return (root->left && !(root->left->left) && !(root->left->right)
                    ? root->left->val
                    : 0) +
               sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};

// iterative
class Solution {
  public:
    int sumOfLeftLeaves(TreeNode *root) {
        if (!root)
            return 0;

        stack<TreeNode *> temp;
        temp.push(root);
        int sum = 0;
        bool might_be_last_left = false;

        // pre-order dfs; bfs should also be ok
        while (!temp.empty()) {
            auto *p = temp.top();
            temp.pop();

            if (might_be_last_left && !(p->left) && !(p->right)) {
                sum += p->val;
                might_be_last_left = false;
            }

            if (p->right) {
                temp.push(p->right);
                might_be_last_left = false;
            }

            if (p->left) {
                temp.push(p->left);
                might_be_last_left = true;
            }
        }

        return sum;
    }
};
