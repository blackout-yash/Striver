// 105. Construct Binary Tree from Preorder and Inorder Traversal
// Link - https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/



class Solution {
public:
	void buildTree(TreeNode* root, int i, int j, int &k, map <int, int> &index, vector<int> &preorder, vector<int> &inorder) {
		root -> val = preorder[k];
		if (i == j) {
			k++;
			return;
		}

		int mid = index[preorder[k]];

		k++;
		if (i <= mid - 1) {
			root -> left = new TreeNode();
			buildTree(root -> left, i, mid - 1, k, index, preorder, inorder);
		}

		if (mid + 1 <= j) {
			root -> right = new TreeNode();
			buildTree(root -> right, mid + 1, j, k, index, preorder, inorder);
		}
	}

	TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder) {
		TreeNode* root = new TreeNode();
		int n = preorder.size(), k = 0;

		map <int, int> index;
		for (int i = 0; i < n; i++) index[inorder[i]] = i;

		buildTree(root, 0, n - 1, k, index, preorder, inorder);

		return root;
	}
};