// 7. Number of Provinces
// Link - https://leetcode.com/problems/number-of-provinces/



class Solution {
public:
	void bfs(int root, int n, vector <int> &vis, vector<vector<int>> &isConnected) {
		vis[root] = 1;
		for (int child = 0; child < n; child++) {
			if (isConnected[root][child]) {
				if (vis[child]) continue;
				bfs(child, n, vis, isConnected);
			}
		}
	}

	int findCircleNum(vector<vector<int>> &isConnected) {
		int n = isConnected.size();
		vector <int> vis(n);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (!vis[i]) {
				ans++;
				bfs(i, n, vis, isConnected);
			}
		}
		return ans;
	}
};