// 787. Cheapest Flights Within K Stops
// Link - https://leetcode.com/problems/cheapest-flights-within-k-stops/



class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
		vector <vector <pair<int, int>>> graph(n);
		for (auto x : flights) graph[x[0]].push_back({x[1], x[2]});

		k++;
		vector <int> vis(n, 1e9);
		vis[src] = 0;

		queue <pair<int, pair<int, int>>> q;
		q.push({k, {0, src}});

		while (!q.empty()) {
			int left = q.front().first,
			    dis = q.front().second.first,
			    node = q.front().second.second;
			q.pop();

			if (left) {
				for (auto it : graph[node]) {
					int currNode = it.first,
					    currDis = it.second;

					if (vis[currNode] > dis + currDis) {
						vis[currNode] = dis + currDis;
						q.push({left - 1, {vis[currNode], currNode}});
					}
				}
			}
		}

		if (vis[dst] == 1e9) return -1;
		return vis[dst];
	}
};