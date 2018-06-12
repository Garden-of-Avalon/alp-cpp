// ref: LC 297 Serialize and Deserialize Binary Tree
// ref: https://github.com/miloyip/misc/blob/master/pntree/pntree.c

// print out a tree from string
//     1
//    / \
//   2   3
//      / \
//     4   5
// "[1,2,3,null,null,4,5]"

#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Tree {
    TreeNode *root = nullptr;

  public:
    // to a single string.
    string serialize() {
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
        clear();

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

    void clear() {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
            delete p;
        }

        root = nullptr;
    }

    int geth(TreeNode *r) {
        return r ? 1 + max(geth(r->left), geth(r->right)) : -1;
    }

    void fillMap(vector<TreeNode *> &nodemap, TreeNode *n, int index) {
        if (!n)
            return;
        nodemap[index] = n;
        fillMap(nodemap, n->left, index * 2 + 1);
        fillMap(nodemap, n->right, index * 2 + 2);
    }
    // serialize version 2 based on fillMap: TODO

    void putchars(char c, int n) {
        while (n--)
            cout << c;
    }

    int printNode(TreeNode *n, int w) { return printf("%*d", w, n->val); }

    void printLeftToParentBranchTop(int w) {
        printf("%*c", w + 1, ' ');
        putchars('_', w - 3);
        printf("/ ");
    }

    void printRightToParentBranchTop(int w) {
        putchar('\\');
        putchars('_', w - 3);
        printf("%*c", w + 2, ' ');
    }

    void printLeftToParentBranchBottom(int w) {
        printf("%*c%*c", w + 1, '/', w - 1, ' ');
    }

    void printRightToParentBranchBottom(int w) {
        printf("%*c%*c", w - 1, '\\', w + 1, ' ');
    }

    void show() {
        if (!root)
            return;

        int depth = geth(root) + 1, i, j, index;
        vector<TreeNode *> nodemap((1 << depth) - 1);
        fillMap(nodemap, root, 0);

        for (j = 0, index = 0; j < depth; j++) {
            int w = 1 << (depth - j + 1);
            if (j > 0) {
                // Top part of node to parent branch
                for (i = 0; i < 1 << j; i++)
                    if (nodemap[index + i])
                        if (i % 2 == 0)
                            printLeftToParentBranchTop(w);
                        else
                            printRightToParentBranchTop(w);
                    else
                        putchars(' ', w * 2);
                putchar('\n');
                // Bottom part of node to parent branch
                for (i = 0; i < 1 << j; i++)
                    if (nodemap[index + i])
                        if (i % 2 == 0)
                            printLeftToParentBranchBottom(w);
                        else
                            printRightToParentBranchBottom(w);
                    else
                        putchars(' ', w * 2);
                putchar('\n');
            }
            // Node content
            for (i = 0; i < 1 << j; i++, index++)
                if (nodemap[index])
                    putchars(' ', w * 2 - printNode(nodemap[index], w));
                else
                    putchars(' ', w * 2);
            putchar('\n');
        }
    }

    Tree() = default;
    Tree(string data) { deserialize(data); }
    ~Tree() { clear(); }
};

int main() {
    Tree T("[5,4,7,3,1,2,3,4]");

    T.show();

    return 0;
}