// Predecessor and Successor
// Link - https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1



void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
	Node* curr = root;
	while (curr != NULL) {
		if (curr -> key < key) {
			pre = curr;
			curr = curr -> right;
		} else curr = curr -> left;
	}

	curr = root;
	while (curr != NULL) {
		if (curr -> key > key) {
			suc = curr;
			curr = curr -> left;
		} else curr = curr -> right;
	}
}