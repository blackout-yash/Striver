// 25. Check for Symmetrical Binary Trees
// Link - https://leetcode.com/problems/symmetric-tree/



class Solution {
public:
	bool isSymmetric(TreeNode* root1, TreeNode* root2) {
		if (root1 == NULL && root2 == NULL) return true;
		else if (root1 == NULL || root2 == NULL) return false;
		else if (root1 -> val != root2 -> val) return false;

		bool ans1 = isSymmetric(root1 -> left, root2 -> right);
		bool ans2 = isSymmetric(root1 -> right, root2 -> left);

		return (ans1 && ans2);
	}

	bool isSymmetric(TreeNode* root) {
		bool ans = isSymmetric(root, root);
		return ans;
	}
};