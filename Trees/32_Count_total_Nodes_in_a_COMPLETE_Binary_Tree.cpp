// 222. Count Complete Tree Nodes
// Link - https://leetcode.com/problems/count-complete-tree-nodes/



class Solution {
public:
	int leftHeight(TreeNode* root) {
		int height = 0;
		while (root != NULL) {
			height++;
			root = root -> left;
		}
		return height;
	}

	int rightHeight(TreeNode* root) {
		int height = 0;
		while (root != NULL) {
			height++;
			root = root -> right;
		}
		return height;
	}

	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;

		int lh = leftHeight(root);
		int rh = rightHeight(root);

		if (lh == rh) return (2 << (lh - 1)) - 1;

		int left = countNodes(root -> left);
		int right = countNodes(root -> right);

		return left + 1 + right;
	}
};