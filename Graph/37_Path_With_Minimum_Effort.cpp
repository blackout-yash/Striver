// 1631. Path With Minimum Effort
// Link - https://leetcode.com/problems/path-with-minimum-effort/



class Solution {
public:
	vector <vector <int>> movement = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	int minimumEffortPath(vector<vector<int>> &heights) {
		int n = heights.size(), m = heights[0].size();
		vector <vector <int>> vis(n, vector <int> (m, 1e9));

		priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
		q.push({0, {0, 0}});
		vis[0][0] = 0;

		while (!q.empty()) {
			auto curr = q.top();
			q.pop();

			int value = curr.first,
			    x = curr. second.first,
			    y = curr.second.second,
			    ht = heights[x][y];

			for (auto z : movement) {
				int currX = x + z[0],
				    currY = y + z[1];
				if (isValid(currX, currY, n, m)) {
					int currHt = heights[currX][currY],
					    currValue = vis[currX][currY],
					    possValue = max(value, abs(currHt - ht));

					if (currValue > possValue) {
						q.push({possValue, {currX, currY}});
						vis[currX][currY] = possValue;
					}
				}
			}
		}

		return vis[n - 1][m - 1];
	}
};