// Delete all occurrences of a given key in a doubly linked list
// Link - https://practice.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1



class Solution {
public:
	void deleteAllOccurOfX(struct Node** head, int x) {
		Node* curr = *head;
		if (curr == NULL) return;
		else if (curr -> next == NULL && curr -> data == x) {
			*head = curr -> next;
			delete(curr);
		}

		while (curr) {
			if (curr -> data == x) {
				if (curr -> prev) {
					Node* next = curr -> next;
					Node* prev = curr -> prev;
					prev -> next = next;
					if (next) next -> prev = prev;
					curr = curr -> next;
				} else {
					Node* next = curr -> next;
					Node* newNode = curr;
					next -> prev = NULL;
					curr = next;
					*head = curr;
					delete newNode;
				}
			} else curr = curr -> next;
		}
	}
};