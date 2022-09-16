// 700. Search in a Binary Search Tree
// Link - https://leetcode.com/problems/search-in-a-binary-search-tree/



// Approach I
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		while (root != NULL) {
			if (root -> val == val) return root;
			root = (root -> val > val) ? root -> left : root -> right;
		}
		return NULL;
	}
};



// Approach II
class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		if (root == NULL) return NULL;
		else if (root -> val == val) return root;

		TreeNode* left = root -> left;
		TreeNode* right = root -> right;
		if (left != NULL && root -> val > val) return searchBST(left, val);

		return searchBST(right, val);
	}
};