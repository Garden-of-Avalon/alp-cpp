// You are given a binary tree in which each node contains an integer value.
// Find the number of paths that sum to a given value.
// The path does not need to start or end at the root or a leaf, but it must go
// downwards (traveling only from parent nodes to child nodes).
// The tree has no more than 1,000 nodes and the values are in the range
// -1,000,000 to 1,000,000.
// Example:
// root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8
//       10
//      /  \
//     5   -3
//    / \    \
//   3   2   11
//  / \   \
// 3  -2   1
// Return 3. The paths that sum to 8 are:
// 1.  5 -> 3
// 2.  5 -> 2 -> 1
// 3. -3 -> 11

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// NEED OPTIMIZATIONS
// preorder traverse
class Solution {
  public:
    int pathSum(TreeNode *root, int sum) {
        if (!root)
            return 0;
        TreeNode *temp = root;
        int result = 0, counter = 0;
        stack<TreeNode *> parents;
        parents.push(root);
        while (!parents.empty()) {
            result += temp->val;
            if (result == sum)
                ++counter;
            if (temp->left)
                parents.push(temp = temp->left);
            else if (temp->right)
                parents.push(temp = temp->right);
            else {
                result -= temp->val;
                parents.pop();
                if (!parents.empty()) {
                    // temp is its parent right child
                    // or (temp is its left child and right is null)
                    // in this case go up in the tree
                    while (temp == parents.top()->right ||
                           !parents.top()->right) {
                        result -= parents.top()->val;
                        temp = parents.top();
                        parents.pop();
                        if (parents.empty())
                            return counter + pathSum(root->left, sum) +
                                   pathSum(root->right, sum);
                    }
                    // now temp is its parent's left child
                    // and its parent right is not null
                    parents.push(temp = parents.top()->right);
                }
            }
        }

        return counter + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};