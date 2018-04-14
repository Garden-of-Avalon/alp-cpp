/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Depth-first search
// https://en.wikipedia.org/wiki/Tree_traversal

// ********************
// Pre-order
// ********************
// recursive
void rpre(TreeNode *root) {
    if (!root)
        return;

    // visit root

    rpre(root->left);
    rpre(root->right);
}

// iterative
void ipre(TreeNode *root) {
    if (!root)
        return;

    stack<TreeNode *> s;
    s.push(root);

    while (!s.empty()) {
        auto *n = s.top();
        s.pop();

        // visit n

        if (n->right)
            s.push(n->right);

        if (n->left)
            s.push(n->left);
    }
}

// ********************
// In-order
// ********************
// recursive
void rin(TreeNode *root) {
    if (!root)
        return;

    rin(root->left);

    // visit root

    rin(root->right);
}

// iterative
void iin(TreeNode *root) {
    stack<TreeNode *> s;

    while (!s.empty() || root)
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            root = s.top();
            s.pop();

            // visit root

            root = root->right;
        }
}

void morrisin(TreeNode *root) {
    TreeNode *pre = nullptr;
    while (root)
        if (!root->left) {
            // visit root

            root = root->right;
        } else {
            pre = root->left;
            while (pre->right && pre->right != root)
                pre = pre->right;

            // now pre is the actual inorder predecessor of root or pre == root
            if (!pre->right) {
                pre->right = root;
                root = root->left;
            } else {
                pre->right = nullptr;

                // visit root

                root = root->right;
            }
        }
}

// ********************
// Post-order
// ********************
// recursive
void rpost(TreeNode *root) {
    if (!root)
        return;

    rpost(root->left);
    rpost(root->right);

    // visit root
}

// iterative
void ipost(TreeNode *root) {
    stack<TreeNode *> s;
    TreeNode *lastvisit = NULL;

    while (!s.empty() || root)
        if (root) {
            s.push(root);
            root = root->left;
        } else {
            auto *peek = s.top();

            if (peek->right && peek->right != lastvisit)
                root = peek->right; // move right
            else {
                // visit peek

                lastvisit = peek;
                s.pop();
                // now root is still NULL
            }
        }
}