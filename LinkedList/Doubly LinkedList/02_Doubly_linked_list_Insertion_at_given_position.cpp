// Doubly linked list Insertion at given position
// Link - https://practice.geeksforgeeks.org/problems/insert-a-node-in-doubly-linked-list/1



void addNode(Node *head, int pos, int data) {
	for (int i = 0; i <= pos; i++) {
		if (i == pos) {
			Node* next = head -> next;
			Node* newNode = new Node(data);

			head -> next = newNode;
			newNode -> next = next;

			newNode -> prev = head;
			if (next) next -> prev = newNode;
		} else head = head -> next;
	}
}