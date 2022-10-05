// Shortest Path in Weighted undirected graph
// Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1



class Solution {
public:
	vector<int> shortestPath(int n, int m, vector <vector <int>>& edges) {
		vector <vector<pair<int, int>>> graph(n + 1);
		for (auto x : edges) {
			graph[x[0]].push_back({x[1], x[2]});
			graph[x[1]].push_back({x[0], x[2]});
		}

		vector <int> dist(n + 1, 1e9), par(n + 1);
		priority_queue <pair<int, int>> pq;
		pq.push({0, 1});
		dist[1] = 0;

		while (!pq.empty()) {
			int wt = pq.top().first,
			    node = pq.top().second;
			pq.pop();

			for (auto it : graph[node]) {
				int child = it.first,
				    newWt = it.second;

				if (wt + newWt < dist[child]) {
					par[child] = node;
					dist[child] = wt + newWt;
					pq.push({dist[child], child});
				}
			}
		}

		vector <int> path;
		if (dist[n] == 1e9) return path = { -1};

		int last = n;
		while (true) {
			path.push_back(last);
			if (last == 1) break;
			else last = par[last];
		} reverse(path.begin(), path.end());

		return path;
	}
};