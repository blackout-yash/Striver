// 994. Rotting Oranges
// Link - https://leetcode.com/problems/rotting-oranges/



class Solution {
public:
	vector <vector <int>> movements = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	void bfs(int n, int m, vector<vector<int>> &vis, vector<vector<int>> &grid) {
		queue <pair <int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 2) {
					q.push({i, j});
					vis[i][j] = 1;
				}
			}
		}

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			int X = curr.first, Y = curr.second;
			grid[X][Y] = 2;

			for (auto child : movements) {
				int currX = X + child[0],
				    currY = Y + child[1];

				if (isValid(currX, currY, n, m)) {
					if (vis[currX][currY] || grid[currX][currY] != 1) continue;
					q.push({currX, currY});
					vis[currX][currY] = 1 + vis[X][Y];
				}
			}
		}
	}

	int orangesRotting(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector <vector <int>> vis(n, vector <int> (m));

		bfs(n, m, vis, grid);

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1) return -1;
				else ans = max(ans, vis[i][j] - 1);
			}
		}

		return ans;
	}
};