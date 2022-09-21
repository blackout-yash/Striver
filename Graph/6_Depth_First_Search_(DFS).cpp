// DFS of Graph
// Link - https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1



class Solution {
public:
	void dfs(int root, vector<int> &vis, vector<int> &ans, vector<int> adj[]) {
		vis[root] = 1;
		ans.push_back(root);

		for (int child : adj[root]) {
			if (vis[child]) continue;
			dfs(child, vis, ans, adj);
		}
	}

	vector<int> dfsOfGraph(int v, vector<int> adj[]) {
		vector <int> ans, vis(v);
		dfs(0, vis, ans, adj);

		return ans;
	}
};