// Serialization is the process of converting a data structure or object into a
// sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There
// is no restriction on how your serialization/deserialization algorithm should
// work. You just need to ensure that a binary search tree can be serialized to
// a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. Your
// serialize and deserialize algorithms should be stateless.

// ref: 297
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root)
            return "N"; // means null

        stringstream ss;
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto *n = q.front();
            q.pop();
            if (n) {
                ss << n->val << ' ';
                q.push(n->left);
                q.push(n->right);
            } else {
                stringstream tempss;
                tempss << "N ";
                while (!q.empty() && !q.front()) {
                    tempss << "N ";
                    q.pop();
                }
                if (!q.empty())
                    ss << tempss.str();
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        string curr;

        TreeNode *root = NULL;
        queue<TreeNode **> q;
        q.push(&root);

        while (ss >> curr) {
            auto **pn = q.front();
            q.pop();
            if (curr != "N") {
                *pn = new TreeNode(stoi(curr));
                q.push(&(*pn)->left);
                q.push(&(*pn)->right);
            }
        }

        return root;
    }
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));