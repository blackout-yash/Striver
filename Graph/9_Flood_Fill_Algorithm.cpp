// 733. Flood Fill
// Link - https://leetcode.com/problems/flood-fill/



class Solution {
public:
	vector <vector <int>> movements = {
		{ -1, 0}, {0, -1}, {0, 1}, {1, 0}
	};

	bool isValid(int i, int j, int n, int m) {
		return i >= 0 && i < n && j >= 0 && j < m;
	}

	void dfs(int x, int y, int n, int m, int prevColor, int color, vector<vector<int>> &vis, vector<vector<int>> &image) {
		vis[x][y] = 1;
		image[x][y] = color;
		for (auto child : movements) {
			int currX = x + child[0], currY = y + child[1];
			if (isValid(currX, currY, n, m)) {
				if (vis[currX][currY] || image[currX][currY] != prevColor) continue;
				dfs(currX, currY, n, m, prevColor, color, vis, image);
			}
		}
	}

	vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
		int n = image.size(), m = image[0].size();
		vector <vector <int>> vis(n, vector <int> (m));

		dfs(sr, sc, n, m, image[sr][sc], color, vis, image);

		return image;
	}
};