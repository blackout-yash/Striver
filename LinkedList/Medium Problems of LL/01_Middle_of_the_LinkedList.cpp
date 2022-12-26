// 876. Middle of the Linked List
// Link - https://leetcode.com/problems/middle-of-the-linked-list/



class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		ListNode* slow = head;
		ListNode* fast = head;

		while (true) {
			if (fast == NULL || fast -> next == NULL) break;
			fast = fast -> next;
			fast = fast -> next;
			slow = slow -> next;
		}

		return slow;
	}
};