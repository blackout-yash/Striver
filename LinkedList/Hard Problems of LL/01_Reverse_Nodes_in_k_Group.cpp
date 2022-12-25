// 25. Reverse Nodes in k-Group
// Link - https://leetcode.com/problems/reverse-nodes-in-k-group/



class Solution {
public:
	ListNode* prev = NULL;
	int len(ListNode* head) {
		int cnt = 0;
		while (head) {
			cnt++;
			head = head -> next;
		}
		return cnt;
	}

	ListNode* reverse(ListNode* &head, int k) {
		ListNode* newHead = NULL;
		ListNode* temp = head;
		int cnt = 0;
		while (cnt != k) {
			ListNode* next = head -> next;
			head -> next = newHead;
			newHead = head;
			head = next;
			cnt++;
		}
		if (prev) prev -> next = newHead;
		prev = temp;
		return newHead;
	}

	ListNode* reverseKGroup(ListNode* head, int k) {
		int size = len(head);
		ListNode* newHead = NULL;
		for (int i = 0; i < size / k; i++) {
			ListNode* temp = reverse(head, k);
			if (newHead == NULL) newHead = temp;
		}
		if (prev) prev -> next = head;
		return newHead;
	}
};