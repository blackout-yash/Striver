// Implementing Dijkstra Algorithm
// Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1



class Solution {
public:
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		set <pair <int, int>> s;
		vector <int> dist(V, 1e9);

		dist[S] = 0;
		s.insert({0, S});

		while (!s.empty()) {
			int dis = (*s.begin()).first;
			int node = (*s.begin()).second;
			s.erase(s.begin());

			for (auto it : adj[node]) {
				int adjNode = it[0],
				    edgeWeight = it[1];

				if (dis + edgeWeight < dist[adjNode]) {
					s.erase({dist[adjNode], adjNode});
					dist[adjNode] = dis + edgeWeight;
					s.insert({dist[adjNode], adjNode});
				}
			}
		}
		return dist;
	}
};