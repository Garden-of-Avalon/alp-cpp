// ref. 297 Serialize and Deserialize Binary Tree

// print out a tree from string
//     1
//    / \
//   2   3
//      / \
//     4   5
// "[1,2,3,null,null,4,5]"

// printtree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <vector>
#include <sstream>
#include <iomanip>
#include <queue>

using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
			}
			else {
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

	//void show() {
	//	if (!root)
	//		return;

	//	queue<TreeNode *> q;
	//	q.push(root);

	//	int w = 128;
	//	vector<string> buff;

	//	// nw - node width is max number of nodes of current line
	//	int nw = 1, ni = 0, buffi = 0;
	//	vector<int> nextpos, currpos(1, w / 2);

	//	while (!q.empty()) {
	//		int space = w / (nw + 1);

	//		if (buff.size() <= buffi)
	//			buff.resize(buffi + 2, string(w, ' '));


	//		for (int i = space, ni = 0; ni < nw && !q.empty(); ++ni, i += space) {
	//			if (!currpos[ni]) {
	//				nextpos.push_back(0);
	//				nextpos.push_back(0);
	//				continue;
	//			}

	//			auto p = q.front();
	//			q.pop();

	//			string temp = to_string(p->val);
	//			copy(temp.begin(), temp.end(), buff[buffi].begin() + i);

	//			if (p->left) {
	//				q.push(p->left);
	//				buff[buffi + 1][i - 2] = '\/';
	//				nextpos.push_back(1);
	//			}
	//			else
	//				nextpos.push_back(0);

	//			if (p->right) {
	//				q.push(p->right);
	//				buff[buffi + 1][i + 2] = '\\';
	//				nextpos.push_back(1);
	//			}
	//			else
	//				nextpos.push_back(0);

	//		}

	//		nw <<= 1;
	//		buffi += 2;

	//		currpos = nextpos;
	//		nextpos.resize(0);
	//	}

	//	for (auto &&ss : buff)
	//		cout << ss << '\n';

	//	return;
	//}

	int geth(TreeNode *r) {
		if (!r)
			return -1;

		if (!(r->left) && !(r->right))
			return 0;

		return max(1 + geth(r->left), 1 + geth(r->right));
	}

	void show() {
		if (!root)
			return;

		int h = geth(root);
		int w =  4 * pow(2, h); // every node at last line need 2 space


		queue<TreeNode *> q;
		q.push(root);

		vector<string> buff;


		for (auto &&ss : buff)
			cout << ss << '\n';

		return;
	}


	Tree() = default;
	Tree(string data) {
		deserialize(data);
	}

	~Tree() {
		clear();
	}
};


int main() {
	Tree T("[5,4,7,3,1,2,3,4]");

	T.show();

	return 0;
}