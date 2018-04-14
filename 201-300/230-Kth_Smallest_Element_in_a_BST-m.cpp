// Given a binary search tree, write a function kthSmallest to find the kth
// smallest element in it.

// Note:
// You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to
// find the kth smallest frequently? How would you optimize the kthSmallest
// routine?

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
    int kthSmallest(TreeNode *root, int k) {
        int gCnt = 0, cand = INT_MIN;
        function<void(TreeNode *)> inorder = [&](TreeNode *r) {
            if (!r || gCnt == k)
                return;

            inorder(r->left);
            if (++gCnt == k) {
                cand = r->val;
                return;
            }
            inorder(r->right);
        };

        inorder(root);

        return cand;
    }
};

// iterative and vector
class Solution {
  public:
    int kthSmallest(TreeNode *root, int k) {
        vector<int> vals;

        stack<TreeNode *> ts;

        while (!ts.empty() || root)
            if (root) {
                ts.push(root);
                root = root->left;
            } else {
                root = ts.top();
                ts.pop();

                // visit root
                vals.push_back(root->val);
                if (vals.size() == k)
                    break;

                root = root->right;
            }

        return vals[k - 1];
    }
};