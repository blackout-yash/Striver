// Introduction to Linked List
// Link - https://practice.geeksforgeeks.org/problems/introduction-to-linked-list/1



class Solution {
public:
	Node* constructLL(vector <int> &arr) {
		Node* head = new Node(arr[0]);
		Node* curr = head;
		for (int i = 1; i < arr.size(); i++) {
			curr -> next = new Node(arr[i]);
			curr = curr -> next;
		}
		return head;
	}
};