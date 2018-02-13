// Given a Binary Search Tree and a target number, return true if there exist
// two elements in the BST such that their sum is equal to the given target.

// Example 1:

// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 9

// Output: True

// Example 2:

// Input:
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7

// Target = 28

// Output: False

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
    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;

        unordered_set<int> m;

        stack<TreeNode *> s;
        s.push(root);

        while (!s.empty()) {
            auto *p = s.top();
            s.pop();

            if (m.find(k - p->val) != m.end())
                return true;

            m.insert(p->val);

            if (p->right)
                s.push(p->right);

            if (p->left)
                s.push(p->left);
        }

        return false;
    }
};

class Solution {
  public:
    bool findTarget(TreeNode *root, int k) {
        unordered_set<int> m;

        stack<TreeNode *> s;
        auto *p = root;

        while (p) {
            if (m.find(k - p->val) != m.end())
                return true;

            m.insert(p->val);

            if (p->right)
                s.push(p->right);

            if (p->left)
                p = p->left;
            else if (!s.empty()) {
                p = s.top();
                s.pop();
            } else
                break;
        }

        return false;
    }
};

class Solution {
    unordered_set<int> m;

  public:
    bool findTarget(TreeNode *root, int k) {
        if (!root)
            return false;

        if (m.find(k - root->val) != m.end())
            return true;

        m.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

// other ideas: use BST search
