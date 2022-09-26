// Topological sort
// Link - https://practice.geeksforgeeks.org/problems/topological-sort/1



class Solution {
public:
	void topoSortUtil(int root, vector <int> &vis, stack <int> &s, vector<int> adj[]) {
		vis[root] = 1;
		for (int child : adj[root]) {
			if (vis[child]) continue;
			topoSortUtil(child, vis, s, adj);
		}
		s.push(root);
	}

	vector<int> topoSort(int V, vector<int> adj[]) {
		stack <int> s;
		vector <int> vis(V), ans;
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			topoSortUtil(i, vis, s, adj);
		}

		while (!s.empty()) {
			ans.push_back(s.top());
			s.pop();
		}

		return ans;
	}
};