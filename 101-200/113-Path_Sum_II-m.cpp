//  Given a binary tree and a sum, find all root-to-leaf paths where each path's
//  sum equals the given sum.
// For example:
// Given the below binary tree and sum = 22,

//               5
//              / \
//             4   8
//            /   / \
//           11  13  4
//          /  \    / \
//         7    2  5   1

// return

// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]

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
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        vector<vector<int>> ret;
        vector<int> curr;

        function<void(TreeNode *, int)> pfind = [&](TreeNode *root, int sum) {
            if (!root)
                return;
            sum -= root->val;
            curr.push_back(root->val);

            if (!sum && !root->left && !root->right)
                ret.push_back(curr);
            else {
                pfind(root->left, sum);
                pfind(root->right, sum);
            }
            curr.pop_back();
        };

        pfind(root, sum);

        return ret;
    }
};