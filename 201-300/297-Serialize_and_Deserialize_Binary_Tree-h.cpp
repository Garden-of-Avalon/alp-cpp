// Serialization is the process of converting a data structure or object into a
// sequence of bits so that it can be stored in a file or memory buffer, or
// transmitted across a network connection link to be reconstructed later in the
// same or another computer environment.

// Design an algorithm to serialize and deserialize a binary tree. There is no
// restriction on how your serialization/deserialization algorithm should work.
// You just need to ensure that a binary tree can be serialized to a string and
// this string can be deserialized to the original tree structure.

// For example, you may serialize the following tree

//     1
//    / \
//   2   3
//      / \
//     4   5

// as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a
// binary tree. You do not necessarily need to follow this format, so please be
// creative and come up with different approaches yourself.

// Note: Do not use class member/global/static variables to store states. Your
// serialize and deserialize algorithms should be stateless.

// Credits:
// Special thanks to @Louis1992 for adding this problem and creating all test
// cases.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// BFS
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        ostringstream ss;
        ss << '[';

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            if (p) {
                ss << p->val;
                q.push(p->left);
                q.push(p->right);
                if (q.front())
                    ss << ',';
            } else {
                ostringstream tempss;
                tempss << ",null,";
                while (!q.empty() && !q.front()) {
                    tempss << "null,";
                    q.pop();
                }
                if (!q.empty())
                    ss << tempss.str();
            }
        }
        ss << ']';

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        TreeNode *root = NULL;
        queue<TreeNode **> q;
        q.push(&root);

        replace(data.begin(), data.end(), ',', ' ');
        data.front() = data.back() = ' ';

        istringstream ss(data);

        string temp;
        while (ss >> temp) {
            if (temp[0] != 'n') {
                *q.front() = new TreeNode(stoi(temp));
                q.push(&(*q.front())->left);
                q.push(&(*q.front())->right);
            }
            q.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));