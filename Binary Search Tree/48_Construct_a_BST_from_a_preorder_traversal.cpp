// 1008. Construct Binary Search Tree from Preorder Traversal
// Link - https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/



// Approach I
class Solution {
public:
	TreeNode* bstFromPreorder(int &i, int max, vector<int> &preorder) {
		if (i == preorder.size() || preorder[i] > max) return NULL;

		TreeNode* root = new TreeNode(preorder[i++]);
		root -> left = bstFromPreorder(i, root -> val, preorder);
		root -> right = bstFromPreorder(i, max, preorder);

		return root;
	}

	TreeNode* bstFromPreorder(vector<int> &preorder) {
		int i = 0;
		return bstFromPreorder(i, 1e9, preorder);
	}
};



// Approach II
class Solution {
public:
	void bstFromPreorder(TreeNode* root, int i, int j, vector <int> &preorder) {
		if (i > j) return;
		else if (i == j) {
			root -> val = preorder[i];
			return;
		}

		int index = j + 1;
		for (int k = i + 1; k <= j; k++) {
			if (preorder[k] > preorder[i]) {
				index = k;
				break;
			}
		}

		root -> val = preorder[i];
		if (i + 1 <= index - 1) {
			root -> left = new TreeNode();
			bstFromPreorder(root -> left, i + 1, index - 1, preorder);
		}

		if (index <= j) {
			root -> right = new TreeNode();
			bstFromPreorder(root -> right, index, j, preorder);
		}
	}

	TreeNode* bstFromPreorder(vector <int> &preorder) {
		int n = preorder.size();
		TreeNode* root = new TreeNode();
		bstFromPreorder(root, 0, n - 1, preorder);

		return root;
	}
};