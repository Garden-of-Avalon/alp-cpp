/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Breadth-first search
// https://en.wikipedia.org/wiki/Tree_traversal

void bfs(TreeNode *root) {
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        auto *n = q.top();
        q.pop();

        // visit logic

        if (n->left)
            q.push(n->left);

        if (n->right)
            q.push(n->right);
    }

    return;
}