// 75. Children Sum Property
// Link - https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723



int update(BinaryTreeNode <int> *root, int prev = 0) {
	if (root == NULL) return 0;

	int curr = max(root -> data, prev);

	int left = update(root -> left, curr);
	int right = update(root -> right, curr);

	(root -> data) += max(curr, left + right) - (root -> data);

	return root -> data;
}

void changeTree(BinaryTreeNode <int> *root) {
	update(root);
	return;
}