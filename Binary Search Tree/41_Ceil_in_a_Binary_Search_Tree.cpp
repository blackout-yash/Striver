// Ceil in BST
// Link - https://practice.geeksforgeeks.org/problems/implementing-ceil-in-bst/1



// Approach I
int findCeil(Node* root, int input) {
	int ans = 1e9;
	while (root != NULL) {
		if (root -> data >= input) {
			ans = min(ans, root -> data);
			root = root -> left;
		} else root = root -> right;
	}

	return (ans == 1e9) ? -1 : ans;
}



// Approach II
int findCeil(Node* root, int input) {
	if (root == NULL) return -1;

	if (root -> data >= input) {
		int ans = findCeil(root -> left, input);
		if (ans == -1) return root -> data;
		return min(ans, root -> data);
	}

	return findCeil(root -> right, input);
}