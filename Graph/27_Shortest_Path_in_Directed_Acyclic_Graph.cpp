// Shortest path in Directed Acyclic Graph
// Link - https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1



class Solution {
public:
	vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
		vector <vector <pair<int, int>>> graph(N);
		for (auto x : edges) graph[x[0]].push_back({x[1], x[2]});

		vector <int> inorder(N);
		for (int i = 0; i < N; i++) {
			for (auto child : graph[i]) inorder[child.first]++;
		}

		queue <int> q;
		for (int i = 0; i < N; i++) {
			if (inorder[i]) continue;
			q.push(i);
		}

		vector <int> topo;
		while (!q.empty()) {
			int curr = q.front();
			q.pop();
			topo.push_back(curr);

			for (auto child : graph[curr]) {
				int v = child.first;
				inorder[v]--;
				if (!inorder[v]) q.push(v);
			}
		}

		vector <int> dis(N, 1e4);
		dis[0] = 0;

		for (auto x : topo) {
			int u = x;
			for (auto child : graph[x]) {
				int v = child.first,
				    wt = child.second;
				dis[v] = min(dis[v], dis[u] + wt);
			}
		}

		for (auto &x : dis) {
			if (x >= 1e4) x = -1;
		}

		return dis;
	}
};