// Implement an iterator over a binary search tree (BST). Your iterator will be
// initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.
// Note: next() and hasNext() should run in average O(1) time and uses O(h)
// memory, where h is the height of the tree.
// Credits:
// Special thanks to @ts for adding this problem and creating all test cases.

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
        while (root) {
            temp.push(root);
            root = root->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !temp.empty(); }

    /** @return the next smallest number */
    int next() {
        TreeNode *resptr = temp.top();
        temp.pop();

        int res = resptr->val;
        resptr = resptr->right;
        while (resptr) {
            temp.push(resptr);
            resptr = resptr->left;
        }
        return res;
    }

  private:
    stack<TreeNode *> temp;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */