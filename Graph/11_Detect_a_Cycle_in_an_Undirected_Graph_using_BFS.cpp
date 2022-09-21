// Detect cycle in an undirected graph
// Link - https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1



class Solution {
public:
	bool bfs(int root, vector <int> &vis, vector <int> adj[]) {
		queue <int> q;
		q.push(root);
		vis[root] = 1;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (int child : adj[curr]) {
				if (vis[child]) {
					if (vis[child] >= vis[curr]) return true;
					continue;
				}
				q.push(child);
				vis[child] = 1 + vis[curr];
			}
		}
		return false;
	}

	bool isCycle(int V, vector<int> adj[]) {
		vector <int> vis(V);
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			if (bfs(i, vis, adj)) return true;
		}
		return false;
	}
};