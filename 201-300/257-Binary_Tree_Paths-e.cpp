//  Given a binary tree, return all root-to-leaf paths.
// For example, given the following binary tree:
//    1
//  /   \
// 2     3
//  \
//   5
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]
// Credits:
// Special thanks to @jianchao.li.fighter for adding this problem and creating
// all test cases.

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
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ret;
        if (!root)
            return ret;

        TreeNode *curr;
        string str;

        stack<pair<TreeNode *, string>> temp;
        temp.push({root, ""});

        while (!temp.empty()) {
            curr = temp.top().first;
            str = temp.top().second;
            temp.pop();

            if (!(curr->left) && !(curr->right))
                ret.push_back(str + to_string(curr->val));

            if (curr->right)
                temp.push({curr->right, str + to_string(curr->val) + "->"});

            if (curr->left)
                temp.push({curr->left, str + to_string(curr->val) + "->"});
        }

        return ret;
    }
};

// Recursive
class Solution {
  public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> ret;
        if (!root)
            return ret;

        string rs = to_string(root->val);

        if (!(root->left) && !(root->right))
            ret.push_back(rs);
        else {
            if (root->left)
                for (auto &&str : binaryTreePaths(root->left))
                    ret.push_back(rs + "->" + str);

            if (root->right)
                for (auto &&str : binaryTreePaths(root->right))
                    ret.push_back(rs + "->" + str);
        }

        return ret;
    }
};

// Ref Java 1
// public
// List<String> binaryTreePaths(TreeNode root) {
//     List<String> answer = new ArrayList<String>();
//     if (root != null)
//         searchBT(root, "", answer);
//     return answer;
// }
// private
// void searchBT(TreeNode root, String path, List<String> answer) {
//     if (root.left == null && root.right == null)
//         answer.add(path + root.val);
//     if (root.left != null)
//         searchBT(root.left, path + root.val + "->", answer);
//     if (root.right != null)
//         searchBT(root.right, path + root.val + "->", answer);
// }

// Ref Java 2
// public
// List<String> binaryTreePaths(TreeNode root) {
//     List<String> paths = new LinkedList<>();
//     if (root == null)
//         return paths;
//     if (root.left == null && root.right == null) {
//         paths.add(root.val + "");
//         return paths;
//     }
//     for (String path : binaryTreePaths(root.left)) {
//         paths.add(root.val + "->" + path);
//     }
//     for (String path : binaryTreePaths(root.right)) {
//         paths.add(root.val + "->" + path);
//     }
//     return paths;
// }