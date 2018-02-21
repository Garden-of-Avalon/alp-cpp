// Given a binary tree, return the bottom-up level order traversal of its nodes'
// values. (ie, from left to right, level by level from leaf to root).

// For example:
// Given binary tree [3,9,20,null,null,15,7],

//     3
//    / \
//   9  20
//     /  \
//    15   7

// return its bottom-up level order traversal as:

// [
//   [15,7],
//   [9,20],
//   [3]
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
    int level(TreeNode *root) {
        if (!root)
            return 0;

        return 1 + max(level(root->left), level(root->right));
    }

  public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret(level(root));

        queue<TreeNode *> q;
        q.push(root);

        for (int i = ret.size() - 1; i >= 0; --i) {
            int n = q.size();
            for (int j = 0; j < n; ++j) {
                ret[i].push_back(q.front()->val);

                if (q.front()->left)
                    q.push(q.front()->left);
                if (q.front()->right)
                    q.push(q.front()->right);

                q.pop();
            }
        }

        return ret;
    }
};

// dfs TODO