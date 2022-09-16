// 114. Flatten Binary Tree to Linked List
// Link - https://leetcode.com/problems/flatten-binary-tree-to-linked-list/



// Approach I - Recursion
class Solution {
public:
	TreeNode* prev = NULL;

	void flatten(TreeNode* root) {
		if (root == NULL) return;

		flatten(root -> right);
		flatten(root -> left);

		root -> left = NULL;
		root -> right = prev;
		prev = root;
	}
};



// Approach II
class Solution {
public:
	void flatten(TreeNode* root) {
		if (root == NULL) return;

		stack <TreeNode*> s;
		s.push(root);

		while (!s.empty()) {
			TreeNode* curr = s.top();
			s.pop();

			if (curr -> right != NULL) s.push(curr -> right);
			if (curr -> left != NULL) s.push(curr -> left);

			curr -> left = NULL;
			if (!s.empty()) curr -> right = s.top();
			else curr -> right = NULL;
		}
	}
};



// Approach III - Morris Traversal
class Solution {
public:
	void flatten(TreeNode* root) {
		TreeNode *curr = root;

		while (curr != NULL) {
			if (curr -> left != NULL) {
				TreeNode *next = curr -> left;

				while (next -> right != NULL) next = next -> right;

				next -> right = curr -> right;
				curr -> right = curr -> left;
				curr -> left = NULL;
			}
			curr = curr -> right;
		}
	}
};