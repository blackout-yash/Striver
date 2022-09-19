// 235. Lowest Common Ancestor of a Binary Search Tree
// Link - https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/



// Approach I
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) return root;

		int val = root -> val;
		if (val > p -> val && val > q -> val) return lowestCommonAncestor(root -> left, p, q);
		else if (val < p -> val && val < q -> val) return lowestCommonAncestor(root -> right, p, q);
		return root;
	}
};



// Approach II
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL || root == p || root == q) return root;

		int val = root -> val;

		TreeNode* left = NULL;
		if (val > p -> val || val > q -> val) left = lowestCommonAncestor(root -> left, p, q);
		TreeNode* right = NULL;
		if (val < p -> val || val < q -> val) right = lowestCommonAncestor(root -> right, p, q);

		if (left == NULL) return right;
		else if (right == NULL) return left;
		return root;
