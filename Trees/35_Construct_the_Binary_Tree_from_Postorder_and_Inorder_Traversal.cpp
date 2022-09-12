// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/



class Solution {
public:
	void buildTree(TreeNode* root, int i, int j, int &k, map <int, int> &index, vector<int> &postorder, vector<int> &inorder) {
		root -> val = postorder[k];
		if (i == j) {
			k--;
			return;
		}

		int mid = index[postorder[k]];

		k--;
		if (mid + 1 <= j) {
			root -> right = new TreeNode();
			buildTree(root -> right, mid + 1, j, k, index, postorder, inorder);
		}

		if (i <= mid - 1) {
			root -> left = new TreeNode();
			buildTree(root -> left, i, mid - 1, k, index, postorder, inorder);
		}
	}

	TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder) {
		TreeNode* root = new TreeNode();
		int n = postorder.size(), k = n - 1;

		map <int, int> index;
		for (int i = 0; i < n; i++) index[inorder[i]] = i;

		buildTree(root, 0, n - 1, k, index, postorder, inorder);

		return root;
	}
};