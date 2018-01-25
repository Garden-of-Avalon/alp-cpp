// Given a binary tree, return the vertical order traversal of its nodes'
// values. (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to
// right.

// Examples:

//     Given binary tree [3,9,20,null,null,15,7],

//        3
//       /\
//      /  \
//      9  20
//         /\
//        /  \
//       15   7

//     return its vertical order traversal as:

//     [
//       [9],
//       [3,15],
//       [20],
//       [7]
//     ]

//     Given binary tree [3,9,8,4,0,1,7],

//          3
//         /\
//        /  \
//        9   8
//       /\   /\
//      /  \ /  \
//      4  0 1   7

//     return its vertical order traversal as:

//     [
//       [4],
//       [9],
//       [3,0,1],
//       [8],
//       [7]
//     ]

//     Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is
//     2 and 1's left child is 5),

//          3
//         / \
//        /   \
//        9    8
//       /\    /\
//      /  \  /  \
//      4  0  1   7
//         \  /
//         \  /
//         2  5

//     return its vertical order traversal as:

//     [
//       [4],
//       [9,5],
//       [3,0,1],
//       [8,2],
//       [7]
//     ]

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
    vector<vector<int>> verticalOrder(TreeNode *root) {
        stack<TreeNode *> temp;
        vector<vector<int>> ret;

        while (root) {
            temp.push(root);
            if(root->right)
                temp.push(root->right);

            if(root->left)
                root = root->left;
            else
                ret.push_back({root->val});
        }
    }
};