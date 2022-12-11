// Articulation Point - I
// Link - https://practice.geeksforgeeks.org/problems/articulation-point-1/1



class Solution {
public:
	int timer = 1;
	void dfs(int root, int par, vector <int> &mark, vector <int> &time, vector <int> &low, vector <int> &vis, vector<int> adj[]) {
		vis[root] = 1;
		time[root] = low[root] = timer;
		timer += 1;
		int unVistedChild = 0;
		for (int child : adj[root]) {
			if (child == par) continue;
			else if (vis[child]) {
				low[root] = min(low[root], time[child]);
				continue;
			}
			dfs(child, root, mark, time, low, vis, adj);
			low[root] = min(low[root], low[child]);
			if (low[child] >= time[root] && par != -1) {
				mark[root] = 1;
			}
			unVistedChild++;
		}

		if (unVistedChild > 1 && par == -1) {
			mark[root] = 1;
		}
	}

	vector <int> articulationPoints(int V, vector<int> adj[]) {
		vector <int> vis(V), mark(V), time(V), low(V);
		for (int i = 0; i < V; i++) {
			if (vis[i]) continue;
			dfs(i, -1, mark, time, low, vis, adj);
		}

		vector <int> ans;
		for (int i = 0; i < V; i++) {
			if (mark[i]) ans.push_back(i);
		}

		if (ans.empty()) return { -1};
		return ans;
	}
};