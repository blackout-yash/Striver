// 230. Kth Smallest Element in a BST
// Link - https://leetcode.com/problems/kth-smallest-element-in-a-bst/



class Solution {
public:
	int child(TreeNode* root) {
		if (root == NULL) return 0;

		int left = child(root -> left);
		int right = child(root -> right);

		return left + 1 + right;
	}

	int kthSmallest(TreeNode* root, int k) {
		int left = 0;
		if (root -> left != NULL) left = child(root -> left);

		if (left + 1 == k) return root -> val;
		else if (left >= k) return kthSmallest(root -> left, k);
		return kthSmallest(root -> right, k - left - 1);
		return 0;
	}
};