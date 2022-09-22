// 785. Is Graph Bipartite?
// Link - https://leetcode.com/problems/is-graph-bipartite/



class Solution {
public:
	bool dfs(int root, vector <int> &vis, vector <int> &color, vector<vector<int>> &graph) {
		vis[root] = 1;
		for (int child : graph[root]) {
			if (vis[child]) {
				if (color[root] == color[child]) return false;
				continue;
			}
			color[child] = !color[root];
			if (!dfs(child, vis, color, graph)) return false;
		}
		return true;
	}

	bool isBipartite(vector<vector<int>> &graph) {
		int n = graph.size();
		vector <int> vis(n), color(n);
		for (int i = 0; i < n; i++) {
			if (vis[i]) continue;
			else if (!dfs(i, vis, color, graph)) return false;
		}
		return true;
	}
};