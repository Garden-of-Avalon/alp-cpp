// Given a binary tree, return the level order traversal of its nodes' values.
// (ie, from left to right, level by level).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its level order traversal as:

// [
//   [3],
//   [9,20],
//   [15,7]
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

// BFS
class Solution {
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root)
            return {};

        queue<TreeNode *> q;
        q.push(root);

        vector<vector<int>> ret;

        while (!q.empty()) {
            ret.push_back({});
            int sz = q.size();
            for (int i = 0; i < sz; ++i) {
                ret.back().push_back(q.front()->val);

                if(q.front()->left)
                    q.push(q.front()->left);

                if(q.front()->right)
                    q.push(q.front()->right);
                
                q.pop();
            }
        }

        return ret;
    }
};