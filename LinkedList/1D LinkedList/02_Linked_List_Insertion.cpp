// Linked List Insertion
// Link - https://practice.geeksforgeeks.org/problems/linked-list-insertion-1587115620/0



class Solution {
public:
	Node *insertAtBegining(Node *head, int x) {
		Node *temp = new Node(x);
		temp -> next =  head;
		return temp;
	}

	Node *insertAtEnd(Node *head, int x)  {
		Node *temp = new Node(x);
		while (head == NULL) return temp;
		Node *curr = head;
		while (true) {
			if (curr -> next == NULL) break;
			else curr = curr -> next;
		}
		curr -> next = temp;
		return head;
	}
};