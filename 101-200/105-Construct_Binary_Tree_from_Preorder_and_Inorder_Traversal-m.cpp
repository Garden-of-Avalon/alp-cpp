// Given preorder and inorder traversal of a tree, construct the binary tree.

// Note:
// You may assume that duplicates do not exist in the tree.

// For example, given

// preorder = [3,9,20,15,7]
// inorder = [9,3,15,20,7]

// Return the following binary tree:

//     3
//    / \
//   9  20
//     /  \
//    15   7

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// iterative
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        stack<TreeNode **> pres;
        TreeNode *root = NULL, **pp = &root;

        int pi = 0, ii = 0;
        while (pi < preorder.size()) {
            *pp = new TreeNode(preorder[pi]);
            pres.push(pp);
            if (preorder[pi] != inorder[ii])
                pp = &(*pp)->left; // go left
            else {
                while (!pres.empty() && (*pres.top())->val == inorder[ii]) {
                    pp = pres.top(); // candidate parent
                    ++ii;
                    pres.pop();
                }
                pp = &(*pp)->right;
            }
            ++pi;
        }

        return root;
    }
};

// recursive
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        unordered_map<int, int> inorder_val_index;
        for (int i = 0; i < inorder.size(); ++i)
            inorder_val_index.emplace(inorder[i], i);

        function<TreeNode *(int, int, int)> build =
            [&](int pst, int ist, int iend) -> TreeNode * {
            if (pst >= preorder.size() || ist > iend)
                return NULL;

            TreeNode *root = new TreeNode(preorder[pst]);
            int index = inorder_val_index[preorder[pst]];

            root->left = build(pst + 1, ist, index - 1);
            // (index - ist) elements go left
            // so right side starts from pst + 1 + index - ist
            root->right = build(pst + 1 + index - ist, index + 1, iend);
            return root;
        };

        return build(0, 0, inorder.size() - 1);
    }
};

// recursive 2: dfs
// actually same as previous one
class Solution {
  public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        function<TreeNode *(int &, int &, TreeNode *)> dfs =
            [&](int &pst, int &ist, TreeNode *pivot) -> TreeNode * {
            if (ist < inorder.size() &&
                (pivot == NULL || inorder[ist] != pivot->val)) {
                TreeNode *root = new TreeNode(preorder[pst++]);
                root->left = dfs(pst, ist, root);
                ++ist;
                root->right = dfs(pst, ist, pivot);
                return root;
            } else
                return NULL;
        };

        int pi = 0, ii = 0;
        return dfs(pi, ii, NULL);
    }
};