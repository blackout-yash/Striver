// Introduction to Doubly Linked List
// Link - https://practice.geeksforgeeks.org/problems/introduction-to-doubly-linked-list/1



class Solution {
public:
	Node* constructDLL(vector <int> &arr) {
		Node* head = new Node(arr[0]);
		Node* temp = head;
		for (int i = 1; i < arr.size(); i++) {
			temp -> next = new Node(arr[i]);
			temp -> next -> prev = temp;
			temp = temp -> next;
		}
		return head;
	}
};