// Given a binary tree, return the vertical order traversal of its nodes'
// values. (ie, from top to bottom, column by column).

// If two nodes are in the same row and column, the order should be from left to
// right.

// Examples:

//     Given binary tree [3,9,20,null,null,15,7],

//        3
//       /\
//      /  \
//      9  20
//         /\
//        /  \
//       15   7

//     return its vertical order traversal as:

//     [
//       [9],
//       [3,15],
//       [20],
//       [7]
//     ]

//     Given binary tree [3,9,8,4,0,1,7],

//          3
//         /\
//        /  \
//        9   8
//       /\   /\
//      /  \ /  \
//      4  0 1   7

//     return its vertical order traversal as:

//     [
//       [4],
//       [9],
//       [3,0,1],
//       [8],
//       [7]
//     ]

//     Given binary tree [3,9,8,4,0,1,7,null,null,null,2,5] (0's right child is
//     2 and 1's left child is 5),

//          3
//         / \
//        /   \
//        9    8
//       /\    /\
//      /  \  /  \
//      4  0  1   7
//         \  /
//         \  /
//         2  5

//     return its vertical order traversal as:

//     [
//       [4],
//       [9,5],
//       [3,0,1],
//       [8,2],
//       [7]
//     ]

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
    vector<vector<int>> verticalOrder(TreeNode *root) {
        if (!root)
            return {};

        queue<pair<TreeNode *, int>> temp;
        temp.push({root, 0});

        vector<vector<int>> retl, retr; // left, right
        auto addtoret = [](vector<vector<int>> &r, TreeNode *n, int i) {
            if (i + 1 > r.size())
                r.resize(i + 1);
            r[i].push_back(n->val);

        };

        int vlen = 0;

        // do bfs
        while (!temp.empty()) {
            root = temp.front().first;
            vlen = temp.front().second;
            temp.pop();

            // return value logic
            if (vlen >= 0)
                addtoret(retr, root, vlen);
            else
                addtoret(retl, root, -vlen - 1);

            if (root->left)
                temp.push({root->left, vlen - 1});

            if (root->right)
                temp.push({root->right, vlen + 1});
        }

        reverse(retl.begin(), retl.end());
        copy(retr.begin(), retr.end(), back_inserter(retl));

        return retl;
    }
};

// other method: instead of retl and retr, use map and vlen as key