//  Given a non-empty binary search tree and a target value, find the value in
//  the BST that is closest to the target.

// Note:

//     Given target value is a floating point.
//     You are guaranteed to have only one unique value in the BST that is
//     closest to the target.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// recursion
class Solution {
  public:
    int closestValue(TreeNode *root, double target) {
        int a = root->val;
        TreeNode *child = target < root->val ? root->left : root->right;
        if (!child)
            return a;
        int b = closestValue(child, target);
        return abs(a - target) < abs(b - target) ? a : b;
    }
};

// binary search
class Solution {
  public:
    int closestValue(TreeNode *root, double target) {
        pair<TreeNode *, TreeNode *> bound = make_pair(nullptr, nullptr);
        while (root) {
            if (target == root->val)
                return target;

            if (target > root->val) {
                bound.first = root;
                root = root->right;
            } else {
                bound.second = root;
                root = root->left;
            }
        }

        return (!bound.second || bound.first && target - bound.first->val <
                                                    bound.second->val - target)
                   ? bound.first->val
                   : bound.second->val;
    }
};

// binary search
class Solution {
  public:
    int closestValue(TreeNode *root, double target) {
        pair<double, double> bound = make_pair(numeric_limits<double>::lowest(),
                                               numeric_limits<double>::max());
        while (root) {
            if (target == root->val)
                return target;

            if (target > root->val) {
                bound.first = root->val;
                root = root->right;
            } else {
                bound.second = root->val;
                root = root->left;
            }
        }

        return (bound.second == numeric_limits<double>::max() ||
                bound.first != numeric_limits<double>::lowest() &&
                    target - bound.first < bound.second - target)
                   ? bound.first
                   : bound.second;
    }
};

// inorder traverse
class Solution {
  public:
    int closestValue(TreeNode *root, double target) {
        TreeNode *prev = nullptr;
        stack<TreeNode *> s;
        while (!s.empty() || root)
            if (root) {
                s.push(root);
                root = root->left;
            } else {
                root = s.top();
                s.pop();

                // visit root
                if (target == root->val)
                    return target;
                if (target < root->val)
                    if (!prev)
                        return root->val;
                    else
                        return target - prev->val > root->val - target
                                   ? root->val
                                   : prev->val;

                prev = root;
                root = root->right;
            }

        return prev->val; // right most
    }
};