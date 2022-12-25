// Search in Linked List
// Link - https://practice.geeksforgeeks.org/problems/search-in-linked-list-1664434326/1



class Solution {
public:
	bool searchKey(int n, struct Node* head, int key) {
		while (true) {
			if (head == NULL) return false;
			else if (head -> data == key) return true;
			head = head -> next;
		}
		return false;
	}
};