// Shortest path in Undirected Graph having unit distance
// Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1



class Solution {
public:
	vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) {
		vector <vector<int>> graph(N);
		for (auto x : edges) {
			graph[x[0]].push_back(x[1]);
			graph[x[1]].push_back(x[0]);
		}

		vector <int> vis(N), dis(N);
		queue <int> q;
		q.push(src);
		vis[src] = 1;

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (int child : graph[curr]) {
				if (vis[child]) continue;
				q.push(child);
				vis[child] = 1;
				dis[child] = 1 + dis[curr];
			}
		}

		for (int i = 0; i < N; i++) {
			if (vis[i]) continue;
			dis[i] = -1;
		}

		return dis;
	}
};