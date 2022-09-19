// 98. Validate Binary Search Tree
// Link - https://leetcode.com/problems/validate-binary-search-tree/



class Solution {
public:
	bool isValidBST(long _min, long _max, TreeNode* root) {
		if (root == NULL) return true;

		long val = root -> val;

		if (_min < val && val < _max) {}
		else return false;

		if (!isValidBST(_min, val, root -> left)) return false;
		if (!isValidBST(val, _max, root -> right)) return false;
		return true;
	}

	bool isValidBST(TreeNode* root) {
		return isValidBST(-1e10, 1e10, root);
	}
};