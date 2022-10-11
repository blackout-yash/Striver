// Distance from the Source (Bellman-Ford Algorithm)
// Link - https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1



class Solution {
public:
	vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
		vector <int> dis(V, 1e8);
		dis[S] = 0;
		for (int i = 0; i < V - 1; i++) {
			for (auto it : edges) {
				int u = it[0],
				    v = it[1],
				    wt = it[2];
				if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
					dis[v] = dis[u] + wt;
				}
			}
		}

		for (auto it : edges) {
			int u = it[0],
			    v = it[1],
			    wt = it[2];
			if (dis[u] != 1e8 && dis[u] + wt < dis[v]) {
				return { -1};
			}
		}

		return dis;
	}
};