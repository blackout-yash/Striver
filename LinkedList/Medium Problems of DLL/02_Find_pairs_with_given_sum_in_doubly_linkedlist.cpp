// Find pairs with given sum in doubly linked list
// Link - https://practice.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1



class Solution {
public:
	vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
		Node* start = head;
		Node* end = head;
		while (true) {
			if (end -> next == NULL) break;
			else end = end -> next;
		}

		vector <pair <int, int>> ans;
		while (true) {
			if (start == end || end -> next == start) break;
			else {
				int temp1 = start -> data,
				    temp2 = end -> data;
				if (temp1 + temp2 == target) {
					ans.push_back({temp1, temp2});
					start = start -> next;
					end = end -> prev;
				} else if (temp1 + temp2 > target) end = end -> prev;
				else start = start -> next;
			}
		}
		return ans;
	}
};