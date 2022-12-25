// Count nodes of linked list
// Link - https://practice.geeksforgeeks.org/problems/count-nodes-of-linked-list/0



class Solution {
public:
	int getCount(struct Node* head) {
		int cnt = 0;
		while (true) {
			if (head == NULL) break;
			else if (head -> next == NULL) {
				cnt++;
				break;
			}
			head = head -> next -> next;
			cnt += 2;
		}
		return cnt;
	}
};