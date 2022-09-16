// 33. Floor in BST
// Link - https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457



int floorInBST(TreeNode<int> * root, int X) {
	int ans = -1;
	while (root != NULL) {
		if (root -> val <= X) {
			ans = max(ans, root -> val);
			root = root -> right;
		} else root = root -> left;
	}
	return ans;
}