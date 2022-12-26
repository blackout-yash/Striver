// Reverse a Doubly Linked List
// Link - https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1



Node* reverseDLL(Node * head) {
	Node* newHead = NULL;
	while (head) {
		Node* next = head -> next;
		head -> prev = head -> next;
		head -> next = newHead;
		newHead = head;
		head = next;
	}
	return newHead;
}