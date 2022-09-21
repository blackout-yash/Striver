// 542. 01 Matrix
// Link - https://leetcode.com/problems/01-matrix/



class Solution {
public:
	vector <vector <int>> movement = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
		int n = mat.size(), m = mat[0].size();
		vector <vector <int>> vis(n, vector <int> (m)), ans(n, vector <int> (m));

		queue <pair <int, int>> q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!mat[i][j]) {
					q.push({i, j});
					vis[i][j] = 1;
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
					if (vis[currX][currY]) continue;
					q.push({currX, currY});
					vis[currX][currY] = 1;
					ans[currX][currY] = 1 + ans[x][y];
				}
			}
		}
		return ans;
	}
};