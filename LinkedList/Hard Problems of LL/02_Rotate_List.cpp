// 61. Rotate List
// Link - https://leetcode.com/problems/rotate-list/description/



class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL) return head;
		int cnt = 0;
		ListNode* temp = head;
		while (temp) {
			cnt++;
			temp = temp -> next;
		}

		k %= cnt;
		if (k == 0) return head;

		temp = head;
		ListNode* newHead;
		while (true) {
			if (k + 1 == cnt) {
				newHead = temp -> next;
				temp -> next = NULL;
				break;
			}
			temp = temp -> next;
			k++;
		}

		temp = newHead;
		while (true) {
			if (temp -> next == NULL) {
				temp -> next = head;
				break;
			}
			temp = temp -> next;
		}
		return newHead;
	}
};