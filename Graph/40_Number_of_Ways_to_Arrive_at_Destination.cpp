// 1976. Number of Ways to Arrive at Destination
// Link - https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/



#define ll long long
class Solution {
public:
	ll add(ll a, ll b, ll m = 1e9 + 7) {a %= m; b %= m; return (((a + b) % m) + m) % m;}

	int countPaths(int n, vector<vector<int>>& roads) {
		vector <vector<pair<int, int>>> graph(n);
		for (auto x : roads) {
			graph[x[0]].push_back({x[1], x[2]});
			graph[x[1]].push_back({x[0], x[2]});
		}

		priority_queue <pair<ll, int>, vector <pair<ll, int>>, greater <pair<ll, int>>> pq;
		pq.push({0, 0});

		vector <ll> vis(n, 1e12), cnt(n);
		vis[0] = 0;
		cnt[0] = 1;

		while (!pq.empty()) {
			ll time = pq.top().first,
			   node = pq.top().second;
			pq.pop();

			for (auto it : graph[node]) {
				ll currNode = it.first,
				   currTime = it.second;

				if (vis[currNode] > time + currTime) {
					vis[currNode] = time + currTime;
					cnt[currNode] = cnt[node];
					pq.push({vis[currNode], currNode});
				} else if (vis[currNode] == time + currTime) cnt[currNode] = add(cnt[currNode], cnt[node]);
			}
		}

		return cnt[n - 1];
	}
};