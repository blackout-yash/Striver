// 130. Surrounded Regions
// Link - https://leetcode.com/problems/surrounded-regions/



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

	void solve(vector<vector<char>> &board) {
		int n = board.size(), m = board[0].size();
		vector <vector <int>> vis(n, vector <int> (m));

		queue <pair <int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (isBoundary(i, j, n, m)) {
					if (board[i][j] == 'O') {
						q.push({i, j});
						vis[i][j] = 1;
					}
				}
			}
		}

		while (!q.empty()) {
			auto curr = q.front();
			q.pop();
			int x = curr.first, y = curr.second;

			for (auto move : movement) {
				int currX = x + move[0], currY = y + move[1];
				if (isValid(currX, currY, n, m)) {
					if (vis[currX][currY] || board[currX][currY] == 'X') continue;
					q.push({currX, currY});
					vis[currX][currY] = 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j]) continue;
				board[i][j] = 'X';
			}
		}
	}
};