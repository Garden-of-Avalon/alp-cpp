// Given a binary tree, find its minimum depth.

// The minimum depth is the number of nodes along the shortest path from the
// root node down to the nearest leaf node.

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
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;

        if (!root->left)
            return 1 + minDepth(root->right);

        if (!root->right)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

// BFS
class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;

        queue<TreeNode *> tq; // temp queue
        tq.push(root);
        int cnt = 0; // level counter

        while (!tq.empty()) {
            ++cnt;
            int sz = tq.size();
            TreeNode *t;
            for (int i = 0; i < sz; ++i) {
                t = tq.front();
                tq.pop();
                if (t->left)
                    tq.push(t->left);
                if (t->right)
                    tq.push(t->right);

                if (!t->left && !t->right)
                    return cnt;
            }
        }

        return numeric_limits<int>::min();
    }
};