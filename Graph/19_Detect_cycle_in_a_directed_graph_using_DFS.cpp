// Detect cycle in a directed graph
// Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1



class Solution {
public:
	bool dfs(int root, vector <int> &vis, vector <int> &path, vector <int> adj[]) {
		vis[root] = path[root] = 1;
		for (int child : adj[root]) {
			if (vis[child]) {
				if (path[child]) return true;
				continue;
			}
			if (dfs(child, vis, path, adj)) return true;
		}
		path[root] = 0;
		return false;
	}

	bool isCyclic(int V, vector<int> adj[]) {
		vector <int> vis(V), path(V);
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			else if (dfs(i, vis, path, adj)) return true;
		}
		return false;
	}
};