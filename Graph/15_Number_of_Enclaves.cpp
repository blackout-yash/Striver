// 1020. Number of Enclaves
// Link - https://leetcode.com/problems/number-of-enclaves/



class Solution {
public:
	vector <vector <int>> movement = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isBoundary(int i, int j, int n, int m) {
		return i == 0 || i + 1 == n || j == 0 || j + 1 == m;
	}

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	void bfs(int X, int Y, int n, int m, vector<vector<int>> &vis, vector<vector <int>> &grid) {
		queue <pair <int, int>> q;
		q.push({X, Y});
		vis[X][Y] = 1;

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			int x = curr.first, y = curr.second;

			for (auto move : movement) {
				int currX = x + move[0], currY = y + move[1];
				if (isValid(currX, currY, n, m)) {
					if (vis[currX][currY] || !grid[currX][currY]) continue;
					q.push({currX, currY});
					vis[currX][currY] = 1;
				}
			}
		}
	}

	int numEnclaves(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector <vector <int>> vis(n, vector <int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j]) continue;
				if (isBoundary(i, j, n, m) && grid[i][j]) {
					bfs(i, j, n, m, vis, grid);
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j]) continue;
				if (grid[i][j]) ans++;
			}
		}
		return ans;
	}
};