// Minimum Spanning Tree
// Link - https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1



class Solution {
public:
	int spanningTree(int V, vector<vector<int>> adj[]) {
		priority_queue <pair <int, pair<int, int>>,
		               vector <pair <int, pair<int, int>>>,
		               greater <pair <int, pair<int, int>>>> pq;
		pq.push({0, {0, -1}});
		vector <int> vis(V);

		int mst = 0;
		vector <pair<int, int>> path;
		while (!pq.empty()) {
			int wt = pq.top().first,
			    node = pq.top().second.first,
			    par = pq.top().second.second;
			pq.pop();

			if (vis[node]) continue;

			vis[node] = 1;
			mst += wt;
			path.push_back({node, par});
			for (auto it : adj[node]) {
				int curr = it[0],
				    currWt = it[1];
				if (!vis[curr]) {
					pq.push({currWt, {curr, node}});
				}
			}
		}

		// For printing the tree
		// 	for (auto x : path) {
		// 		cout << "Node: " << x.first << " Parent: " << x.second << endl;
		// 	}
		return mst;
	}
};