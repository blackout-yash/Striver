// Copy List with Random Pointer
// Link - https://leetcode.com/problems/copy-list-with-random-pointer/



// Approach I
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) return head;

		Node* temp = head;
		while (temp) {
			Node* dummy = new Node(temp -> val);
			dummy -> next = temp -> next;
			temp -> next = dummy;
			temp = temp -> next -> next;
		}

		temp = head;
		Node* newHead = head -> next;
		while (temp) {
			Node* next = temp -> next;
			Node* random = temp -> random;
			if (random) {
				Node* randomNext = random -> next;
				next -> random = randomNext;
			}
			temp = temp -> next -> next;
		}

		temp = head;
		Node* alpha = newHead;
		while (temp) {
			temp -> next = temp -> next -> next;
			if (alpha -> next) alpha -> next = alpha -> next -> next;
			temp = temp -> next;
			alpha = alpha -> next;
		}

		return newHead;
	}
};



// Approach II
class Solution {
public:
	Node* copyRandomList(Node* head) {
		map <Node*, Node*> m;
		Node* temp = head;
		while (temp) {
			m[temp] = new Node(temp -> val);
			temp = temp -> next;
		}

		temp = head;
		while (temp) {
			Node* dummy = m[temp];
			dummy -> next = m[temp -> next];
			dummy -> random = m[temp -> random];
			temp = temp -> next;
		}

		return m[head];
	}
};