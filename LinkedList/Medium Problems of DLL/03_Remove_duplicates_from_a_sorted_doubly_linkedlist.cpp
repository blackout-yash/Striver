// Remove duplicates from a sorted doubly linked list
// Link - https://practice.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1



class Solution {
public:
	void removeDuplicates(struct Node **head) {
		Node* curr = *head;
		while (curr) {
			Node* prev = curr -> prev;
			if (prev && prev -> data == curr -> data) {
				Node* next = curr -> next;
				prev -> next = next;
				if (next) next -> prev = prev;
			}
			curr = curr -> next;
		}
	}
};