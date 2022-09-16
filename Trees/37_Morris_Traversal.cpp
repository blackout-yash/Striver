// 94. Binary Tree Inorder Traversal
// Link - https://leetcode.com/problems/binary-tree-inorder-traversal/



class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector <int> inorder;
		if (root == NULL) return inorder;

		while (root != NULL) {
			if (root -> left == NULL) {
				inorder.push_back(root -> val);
				root = root -> right;
			} else {
				TreeNode * next = root -> left;
				while (next -> right != NULL && next -> right != root) {
					next = next -> right;
				}

				if (next -> right == NULL) {
					next -> right = root;
					root = root -> left;
				} else {
					next -> right = NULL;
					inorder.push_back(root -> val);
					root = root -> right;
				}
			}
		}
		return inorder;
	}
};





// 144. Binary Tree Preorder Traversal
// Link - https://leetcode.com/problems/binary-tree-preorder-traversal/




class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector <int> preorder;
		if (root == NULL) return preorder;

		while (root != NULL) {
			if (root -> left == NULL) {
				preorder.push_back(root -> val);
				root = root -> right;
			} else {
				TreeNode * next = root -> left;
				while (next -> right != NULL && next -> right != root) {
					next = next -> right;
				}

				if (next -> right == NULL) {
					next -> right = root;
					preorder.push_back(root -> val);
					root = root -> left;
				} else {
					next -> right = NULL;
					root = root -> right;
				}
			}
		}
		return preorder;
	}
};