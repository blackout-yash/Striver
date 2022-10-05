// Implementing Dijkstra Algorithm
// Link - https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1



class Solution {
public:
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		vector <int> dist(V, 1e9);

		dist[S] = 0;
		pq.push({0, S});

		while (!pq.empty()) {
			int dis = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			for (auto it : adj[node]) {
				int adjNode = it[0],
				    edgeWeight = it[1];

				if (dis + edgeWeight < dist[adjNode]) {
					dist[adjNode] = dis + edgeWeight;
					pq.push({dist[adjNode], adjNode});
				}
			}
		}
		return dist;
	}
}; class Solution {
public:
	vector <int> dijkstra(int V, vector<vector<int>> adj[], int S) {
		priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

		vector <int> dist(V, 1e9);

		dist[S] = 0;
		pq.push({0, S});

		while (!pq.empty()) {
			int dis = pq.top().first;
			int node = pq.top().second;
			pq.pop();

			for (auto it : adj[node]) {
				int adjNode = it[0],
				    edgeWeight = it[1];

				if (dis + edgeWeight < dist[adjNode]) {
					dist[adjNode] = dis + edgeWeight;
					pq.push({dist[adjNode], adjNode});
				}
			}
		}
		return dist;
	}
};