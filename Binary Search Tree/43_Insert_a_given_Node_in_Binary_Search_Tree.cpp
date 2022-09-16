// 701. Insert into a Binary Search Tree
// Link - https://leetcode.com/problems/insert-into-a-binary-search-tree/



// Approach I
class Solution {
public:
	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == NULL) return root = new TreeNode(val);

		TreeNode *curr = root;
		while (true) {
			if (curr -> val > val) {
				if (curr -> left == NULL) {
					curr -> left = new TreeNode(val);
					break;
				} curr = curr -> left;
			} else {
				if (curr -> right == NULL) {
					curr -> right = new TreeNode(val);
					break;
				} curr = curr -> right;
			}
		}

		return root;
	}
};



// Approach II
class Solution {
public:
	void _insertIntoBST(TreeNode* root, int val) {
		if (root -> val > val) {
			if (root -> left == NULL) {
				root -> left = new TreeNode(val);
				return;
			}
			_insertIntoBST(root -> left, val);
		}
		else {
			if (root -> right == NULL) {
				root -> right = new TreeNode(val);
				return;
			}
			_insertIntoBST(root -> right, val);
		}
	}

	TreeNode* insertIntoBST(TreeNode* root, int val) {
		if (root == NULL) return root = new TreeNode(val);
		_insertIntoBST(root, val);
		return root;
	}
};