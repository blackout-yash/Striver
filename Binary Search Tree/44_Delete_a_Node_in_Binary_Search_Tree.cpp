// 450. Delete Node in a BST
// Link - https://leetcode.com/problems/delete-node-in-a-bst/



class Solution {
public:
	void deleteNode(bool isLeft, TreeNode* par, TreeNode* curr) {
		if (curr -> left == NULL && curr -> right == NULL) (isLeft) ? par -> left = NULL : par -> right = NULL;
		else if (curr -> left == NULL) (isLeft) ? par -> left = curr -> right : par -> right = curr -> right;
		else if (curr -> right == NULL) (isLeft) ? par -> left = curr -> left : par -> right = curr -> left;
		else {
			(isLeft) ? par -> left = curr -> right : par -> right = curr -> right;
			TreeNode* temp = curr -> right;
			while (temp -> left != NULL) temp = temp -> left;
			temp -> left = curr -> left;
		} curr = NULL;
	}

	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == NULL) return root;
		else if (root -> val == key) {
			TreeNode* par = new TreeNode();
			deleteNode(true, par, root);
			return par -> left;
		}

		TreeNode* curr = root;
		while (curr != NULL) {
			if (curr -> left != NULL && curr -> left -> val == key) {
				deleteNode(true, curr, curr -> left);
				break;
			} else if (curr -> right != NULL && curr -> right -> val == key) {
				deleteNode(false, curr, curr -> right);
				break;
			}

			if (curr -> val > key) curr = curr -> left;
			else curr = curr -> right;
		}
		return root;
	}
};