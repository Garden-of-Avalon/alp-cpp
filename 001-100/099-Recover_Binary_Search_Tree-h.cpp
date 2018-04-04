//  Two elements of a binary search tree (BST) are swapped by mistake.
// Recover the tree without changing its structure.
// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a
// constant space solution?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// Morris in-order traversal - real O(1) space
class Solution {
  public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> wrong;

        TreeNode *pre = nullptr, *curr = root, *last_vis = nullptr;

        while (curr) {
            if (!curr->left) {
                // visit curr // mark1
                if (last_vis && last_vis->val > curr->val) {
                    if (wrong.empty()) {
                        wrong.push_back(last_vis);
                        wrong.push_back(curr);
                    } else
                        wrong.back() = curr;
                }
                last_vis = curr; // let mark1 works correct

                curr = curr->right;
            } else {
                pre = curr->left;
                while (pre->right && pre->right != curr)
                    pre = pre->right;

                if (!pre->right) {
                    // modify the tree, build a circle here
                    pre->right = curr;
                    curr = curr->left;
                } else {
                    // revert the modification
                    pre->right = NULL;

                    // visit curr
                    if (last_vis->val > curr->val) {
                        if (wrong.empty()) {
                            wrong.push_back(last_vis);
                            wrong.push_back(curr);
                        } else
                            wrong.back() = curr;
                    }
                    last_vis = curr; // let mark1 works correct

                    curr = curr->right;
                }
            }
        }

        swap(wrong[0]->val, wrong[1]->val);
    }
};

// exchange node value, much easier
class Solution {
  public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode *> wrong;

        // iterative in-order traverse
        TreeNode *pre = new TreeNode(INT_MIN), *origin_pre = pre;

        stack<TreeNode *> st;
        while (!st.empty() || root) {
            if (root) {
                st.push(root);
                root = root->left;
            } else {
                root = st.top();
                st.pop();

                // visit root
                if (pre->val > root->val) {
                    if (wrong.empty()) {
                        wrong.push_back(pre);
                        wrong.push_back(root);
                    } else
                        wrong.back() = root;
                }
                pre = root;

                root = root->right;
            }
        }
        delete origin_pre;

        swap(wrong[0]->val, wrong[1]->val);
    }
};

// exchange real nodes
// because LeetCode test original tree structure, so not work
class Solution {
    // use double pointers to handle parents
    // ptr == &(parent->left or right)
    // we only need to change node and their child
    void swap2nodes(TreeNode **pta, TreeNode **ptb) {
        swap(*pta, *ptb);
        swap((*pta)->left, (*ptb)->left);
        swap((*pta)->right, (*ptb)->right);
    }

  public:
    void recoverTree(TreeNode *root) {
        vector<TreeNode **> wrong;

        // iterative in-order traverse
        TreeNode *pre = new TreeNode(INT_MIN);
        TreeNode **preptr = &pre, **currptr = &root;
        stack<TreeNode **> st;
        while (!st.empty() || *currptr) {
            if (*currptr) {
                st.push(currptr);
                currptr = &(*currptr)->left;
            } else {
                currptr = st.top();
                st.pop();

                // visit curr
                // cout << (*currptr)->val << ' ';
                if ((*preptr)->val > (*currptr)->val) {
                    if (wrong.empty()) {
                        wrong.push_back(preptr);
                        wrong.push_back(currptr);
                    } else
                        wrong.back() = currptr;
                }
                preptr = currptr;

                currptr = &(*currptr)->right;
            }
        }

        // cout << endl;
        // cout << wrong.size() << endl;
        // for (auto &&ptr : wrong) {
        //     cout << (*ptr)->val << endl;
        // }

        swap2nodes(wrong[0], wrong[1]);

        // [-1,0,2,1] output 1, 0, 2, -1
        // cout << root->val << 'x' << endl;
        // cout << root->left->val << 'x' << endl;
        // cout << root->right->val << 'x' << endl;
        // cout << root->left->left->val << 'x' << endl;

        delete pre;
    }
};