// 23. Merge k Sorted Lists
// Link - https://leetcode.com/problems/merge-k-sorted-lists/



class cmp {
public:
	bool operator()(ListNode* a, ListNode* b) {
		if ((a -> val) > (b -> val)) return true;
		else return false;
	}
};

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*> &lists) {
		ListNode* temp = new ListNode();
		ListNode* head = temp;
		priority_queue <ListNode*, vector <ListNode*>, cmp> pq;
		for (auto x : lists) {
			if (x) pq.push(x);
		}

		while (!pq.empty()) {
			ListNode* dummy = pq.top();
			pq.pop();

			temp -> next = dummy;
			temp = temp -> next;
			if (dummy -> next) pq.push(dummy -> next);
		}
		return head -> next;
	}
};