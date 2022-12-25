// Delete a Node in Single Linked List
// Link - https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1



Node* deleteNode(Node *head, int x) {
	if (x == 1) return head -> next;

	int ind = 2;
	Node* prev = head;
	Node* curr = head -> next;
	while (true) {
		if (ind == x) {
			if (curr -> next == NULL) prev -> next = NULL;
			else prev -> next = curr -> next;
			break;
		}
		ind += 1;
		prev = curr;
		curr = curr -> next;
	}
	return head;
}