// Number of Distinct Islands
// Link - https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1



class Solution {
public:
	vector <vector <int>> movement = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	vector <pair <int, int>> bfs(int X, int Y, int n, int m, vector<vector<int>> &vis, vector<vector <int>> &grid) {
		queue <pair <int, int>> q;
		q.push({X, Y});
		vis[X][Y] = 1;

		int sr = X, sc = Y;
		vector <pair <int, int>> ans;
		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			int x = curr.first, y = curr.second;

			ans.push_back({x - sr, y - sc});
			for (auto move : movement) {
				int currX = x + move[0], currY = y + move[1];
				if (isValid(currX, currY, n, m)) {
					if (vis[currX][currY] || !grid[currX][currY]) continue;
					q.push({currX, currY});
					vis[currX][currY] = 1;
				}
			}
		}
		return ans;
	}

	int countDistinctIslands(vector<vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector <vector <int>> vis(n, vector <int> (m));

		set <vector <pair <int, int>>> s;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] || !grid[i][j]) continue;
				s.insert(bfs(i, j, n, m, vis, grid));
			}
		}

		int ans = s.size();
		return ans;
	}
};