// Merge k Sorted Arrays
// Link - https://practice.geeksforgeeks.org/problems/merge-k-sorted-arrays/1



#define ppi pair<int, pair<int, int>>
class Solution {
public:
	vector<int> mergeKArrays(vector <vector<int>> arr, int k) {
		vector <int> ans;
		priority_queue <ppi, vector <ppi>, greater <ppi>> pq;
		for (int i = 0; i < k; i++) pq.push({arr[i][0], {i, 0}});
		while (!pq.empty()) {
			auto it = pq.top();
			int num = it.first,
			    x = it.second.first,
			    y = it.second.second;
			pq.pop();

			ans.push_back(num);
			if (y + 1 != k) pq.push({arr[x][y + 1], {x, y + 1}});
		}
		return ans;
	}
};