// The thief has found himself a new place for his thievery again. There is only
// one entrance to this area, called the "root." Besides the root, each house
// has one and only one parent house. After a tour, the smart thief realized
// that "all houses in this place forms a binary tree". It will automatically
// contact the police if two directly-linked houses were broken into on the same
// night.
// Determine the maximum amount of money the thief can rob tonight without
// alerting the police.
// Example 1:
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
// Example 2:
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
// Maximum amount of money the thief can rob = 4 + 5 = 9.
// Credits:
// Special thanks to @dietpepsi for adding this problem and creating all test
// cases.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// iterative DFS
class Solution {
  public:
    int rob(TreeNode *root) {
        if (!root)
            return 0;

        TreeNode *temp = root;
        stack<TreeNode *> parents;
        parents.push(root);
        while (!parents.empty()) {
            if (temp->left)
                parents.push(temp = temp->left);
            else if (temp->right)
                parents.push(temp = temp->right);
            else {
                parents.pop();
                if (!parents.empty()) {
                    while (temp == parents.top()->right ||
                           !parents.top()->right) {
                        temp = parents.top();
                        parents.pop();
                        // update node value
                        temp->val = std::max(
                            temp->val +
                                (temp->left
                                     ? (temp->left->left ? temp->left->left->val
                                                         : 0) +
                                           (temp->left->right
                                                ? temp->left->right->val
                                                : 0)
                                     : 0) +
                                (temp->right
                                     ? (temp->right->left
                                            ? temp->right->left->val
                                            : 0) +
                                           (temp->right->right
                                                ? temp->right->right->val
                                                : 0)
                                     : 0),
                            (temp->left ? temp->left->val : 0) +
                                (temp->right ? temp->right->val : 0));
                        if (parents.empty())
                            return root->val;
                    }
                    parents.push(temp = parents.top()->right);
                }
            }
        }

        return root->val;
    }
};

// Time limit exceed.
// class Solution {
//   public:
//     int rob(TreeNode *root) {
//         if (!root)
//             return 0;
//         return std::max(
//             root->val +
//                 (root->left ? rob(root->left->left) + rob(root->left->right)
//                             : 0) +
//                 (root->right ? rob(root->right->left) +
//                 rob(root->right->right)
//                              : 0),
//             rob(root->left) + rob(root->right));
//     }
// };