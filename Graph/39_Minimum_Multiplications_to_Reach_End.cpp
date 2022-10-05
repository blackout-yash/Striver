// Minimum Multiplications to reach End
// Link - https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1



class Solution {
public:
	int minimumMultiplications(vector<int> &arr, int start, int end) {
		int mod = 1e5;

		vector <int> vis(mod);
		vis[start % mod] = 1;

		queue <int> q;
		q.push(start % mod);

		int cnt = 0;
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				int node = q.front();
				q.pop();

				if (node == end) return cnt;

				for (auto x : arr) {
					int currNode = (((node * x) % mod) + mod) % mod;
					if (vis[currNode]) continue;
					q.push(currNode);
					vis[currNode] = 1;
				}
			} cnt++;
		}

		return -1;
	}
};