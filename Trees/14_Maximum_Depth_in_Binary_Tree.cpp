// 104. Maximum Depth of Binary Tree
// Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/



#include <iostream>

using namespace std;

class TreeNode {
public:
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int data) {
		val = data;
		left = right = NULL;
	}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		if (root == NULL) return 0;

		int left = maxDepth(root -> left);
		int right = maxDepth(root -> right);

		return 1 + max(left, right);
	}
};

int main() {
	class TreeNode* root = new TreeNode(1);
	root -> left = new TreeNode(2);
	root -> right = new TreeNode(3);
	root -> left -> left = new TreeNode(4);
	root -> left -> right = new TreeNode(5);
	root -> left -> right -> left = new TreeNode(6);
	root -> right -> left = new TreeNode(7);
	root -> right -> right = new TreeNode(8);
	root -> right -> right ->left = new TreeNode(9);
	root -> right -> right ->right = new TreeNode(10);

	Solution sol;
	cout << sol.maxDepth(root);

	return 0;
}