// 802. Find Eventual Safe States
// Link - https://leetcode.com/problems/find-eventual-safe-states/



class Solution {
public:
	bool dfs(int root, vector <int> &vis, vector <int> &isSafe, vector<vector<int>> &graph) {
		vis[root] = 1;
		if (graph[root].empty()) return isSafe[root] = true;

		for (int child : graph[root]) {
			if (vis[child]) {
				if (!isSafe[child]) return isSafe[root] = false;
				continue;
			}
			if (!dfs(child, vis, isSafe, graph)) return isSafe[child] = isSafe[root] = false;
		}
		return isSafe[root] = true;
	}

	vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
		int n = graph.size();
		vector <int> vis(n), isSafe(n), ans;
		for (int i = 0; i < n; i++) {
			if (vis[i]) {
				if (isSafe[i]) ans.push_back(i);
			} else if (dfs(i, vis, isSafe, graph)) ans.push_back(i);
		}
		return ans;
	}
};