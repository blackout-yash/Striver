// 1192. Critical Connections in a Network
// Link - https://leetcode.com/problems/critical-connections-in-a-network/



class Solution {
public:
	void dfs(int root, int par, int &timer, vector <int> &time, vector <int> &low, vector <int> &vis, vector <vector<int>> &graph, vector <vector<int>> &bridges) {
		vis[root] = 1;
		time[root] = low[root] = timer;
		timer++;

		for (int child : graph[root]) {
			if (child == par) continue;
			else if (vis[child]) {
				low[root] = min(low[root], low[child]);
				continue;
			}

			dfs(child, root, timer, time, low, vis, graph, bridges);
			low[root] = min(low[root], low[child]);
			if (low[child] > time[root]) {
				bridges.push_back({root, child});
			}
		}
	}

	vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections) {
		vector <int> vis(n), time(n), low(n);
		vector <vector<int>> graph(n), bridges;
		for (auto x : connections) {
			graph[x[0]].push_back(x[1]);
			graph[x[1]].push_back(x[0]);
		}

		int timer = 1;
		dfs(0, -1, timer, time, low, vis, graph, bridges);

		return bridges;
	}
};