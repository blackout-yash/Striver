// Detect cycle in an undirected graph
// Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1



class Solution {
public:
	bool dfs(int root, int par, vector <int> &vis, vector <int> adj[]) {
		vis[root] = 1;
		for (int child : adj[root]) {
			if (vis[child]) {
				if (child != par) return true;
				continue;
			}
			if (dfs(child, root, vis, adj)) return true;
		}
		return false;
	}

	bool isCycle(int V, vector<int> adj[]) {
		vector <int> vis(V);
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			if (dfs(i, -1, vis, adj)) return true;
		}
		return false;
	}
};