// 85. Maximal Rectangle
// Link - https://leetcode.com/problems/maximal-rectangle/



#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>> &matrix) {
		int n = matrix.size(), m = matrix[0].size();
		vector <vector<pair<int, int>>> dp(n, vector<pair<int, int>> (m));

		int ans = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (matrix[i][j] == '1') {
					int row = 1, col = 1;

					if (j) row += dp[i][j - 1].first;
					if (i) col += dp[i - 1][j].second;

					dp[i][j] = {row, col};

					row = 0; col = 1e9;
					for (int k = i; k >= 0; k--) {
						if (matrix[k][j] == '1') {
							row++; col = min(col, dp[k][j].first);
							ans = max(ans, row * col);
						} else break;
					}
					ans = max(ans, row * col);
				}
			}
		}
		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <vector<char>> matrix(n, vector<char> (m));
	for (auto &x : matrix) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.maximalRectangle(matrix);

	return 0;
}
