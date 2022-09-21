// Find the number of islands
// Link - https://practice.geeksforgeeks.org/problems/find-the-number-of-islands/1



class Solution {
public:
	vector <vector <int>> movements = {
		{ -1, -1}, { -1, 0}, { -1, 1},
		{0, -1}, {0, 1},
		{1, -1}, {1, 0}, {1, 1}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	void dfs(int x, int y, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid) {
		vis[x][y] = 1;
		for (auto child : movements) {
			int currX = x + child[0], currY = y + child[1];
			if (isValid(currX, currY, n, m)) {
				if (vis[currX][currY] || grid[currX][currY] == '0') continue;
				dfs(currX, currY, n, m, vis, grid);
			}
		}
	}

	int numIslands(vector<vector<char>>& grid) {
		int n = grid.size(), m = grid[0].size();
		vector <vector <int>> vis(n, vector <int> (m));

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1') {
					if (vis[i][j]) continue;
					dfs(i, j, n, m, vis, grid);
					ans++;
				}
			}
		}
		return ans;
	}
};