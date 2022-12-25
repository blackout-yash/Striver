// Flattening a Linked List
// Link - https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1



Node *merge(Node *head1, Node *head2) {
	Node* head = new Node(0);
	Node* temp = head;

	while (head1 && head2) {
		if ((head1 -> data) > (head2 -> data)) {
			head -> bottom = head2;
			head2 = head2 -> bottom;
		} else {
			head -> bottom = head1;
			head1 = head1 -> bottom;
		} head = head -> bottom;
	}

	while (head1) {
		head -> bottom = head1;
		head1 = head1 -> bottom;
		head = head -> bottom;
	}

	while (head2) {
		head -> bottom = head2;
		head2 = head2 -> bottom;
		head = head -> bottom;
	}
	head -> bottom = NULL;

	return temp -> bottom;
}

Node *flatten(Node *root) {
	if (root == NULL || root -> next == NULL) return root;
	Node* newHead = root;
	root = root -> next;
	while (root) {
		newHead = merge(newHead, root);
		root = root -> next;
	}

	return newHead;
}