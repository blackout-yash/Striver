// 110. Balanced Binary Tree
// Link - https://leetcode.com/problems/balanced-binary-tree/



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
	int maxDepth(bool &ans, TreeNode* root) {
		if (root == NULL) return 0;

		int left = maxDepth(ans, root -> left);
		int right = maxDepth(ans, root -> right);

		if (abs(left - right) > 1) ans = false;

		return 1 + max(left, right);
	}

	bool isBalanced(TreeNode* root) {
		bool ans = true;
		maxDepth(ans, root);

		return ans;
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
	cout << sol.isBalanced(root);

	return 0;
}