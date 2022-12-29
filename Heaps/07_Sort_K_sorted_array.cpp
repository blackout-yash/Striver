// Nearly sorted
// Link - https://practice.geeksforgeeks.org/problems/nearly-sorted-1587115620/1



class Solution {
public:
	vector <int> nearlySorted(int arr[], int n, int k) {
		vector <int> ans;
		priority_queue <int, vector <int>, greater <int>> pq;
		for (int i = 0; i < n; i++) {
			pq.push(arr[i]);
			if (pq.size() > k) {
				ans.push_back(pq.top());
				pq.pop();
			}
		}

		while (!pq.empty()) {
			ans.push_back(pq.top());
			pq.pop();
		}

		return ans;
	}
};