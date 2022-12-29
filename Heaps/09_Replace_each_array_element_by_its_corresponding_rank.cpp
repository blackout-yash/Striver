// Replace elements by its rank in the array
// Link - https://practice.geeksforgeeks.org/problems/replace-elements-by-its-rank-in-the-array/1



#define pp pair <int, int>
class Solution {
public:
	vector<int> replaceWithRank(vector<int> &arr, int n) {
		priority_queue <pp, vector <pp>, greater <pp>> pq;
		for (int i = 0; i < n; i++) pq.push({arr[i], i});

		int prev = -1, rank = 0;
		vector <int> ans(n);
		for (int i = 1; i <= n; i++) {
			int num = pq.top().first,
			    ind = pq.top().second;
			pq.pop();

			if (num == prev) ans[ind] = rank;
			else {
				rank++;
				ans[ind] = rank;
				prev = num;
			}
		}
		return ans;
	}
};