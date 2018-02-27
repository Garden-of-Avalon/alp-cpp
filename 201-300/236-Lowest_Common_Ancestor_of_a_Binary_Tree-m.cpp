//  Given a binary tree, find the lowest common ancestor (LCA) of two given
//  nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor
// is defined between two nodes v and w as the lowest node in T that has both v
// and w as descendants (where we allow a node to be a descendant of itself).”

//         _______3______
//        /              \
//     ___5__          ___1__
//    /      \        /      \
//    6      _2       0       8
//          /  \
//          7   4

// For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3. Another
// example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of
// itself according to the LCA definition.

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || p == root || q == root)
            return root;

        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);

        return !left ? right : !right ? left : root;
    }
};

// iterative TODO

// not good
class Solution {
    bool isIn(TreeNode *root, TreeNode *p) {
        if (!root)
            return false;
        if (root == p)
            return true;
        return isIn(root->left, p) || isIn(root->right, p);
    }

  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || p == root || q == root)
            return NULL;
        if (p == q)
            return p;

        TreeNode *candidate = NULL;

        // bfs

        queue<TreeNode *> que;
        que.push(root);

        while (!que.empty()) {
            auto temp = que.front();
            que.pop();

            if (isIn(temp, p) && isIn(temp, q))
                candidate = temp;

            if (temp->left)
                que.push(temp->left);
            if (temp->right)
                que.push(temp->right);
        }

        return candidate;
    }
};