// Delete node in Doubly Linked List
// Link - https://practice.geeksforgeeks.org/problems/delete-node-in-doubly-linked-list/1



class Solution {
public:
	Node* deleteNode(Node *head, int x) {
		if (x == 1) return head -> next;

		Node* temp = head;
		for (int i = 1; i < x; i++) {
			if (i + 1 == x) {
				Node* next = head -> next -> next;
				head -> next = next;
				if (next) next -> prev = head;
			} else head = head -> next;
		}
		return temp;
	}
};