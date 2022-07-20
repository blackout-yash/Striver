// 64. Minimum Path Sum
// Link - https://leetcode.com/problems/minimum-path-sum/



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

	int minPathSum(vector <vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector <vector<int>> dp(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) dp[i][j] = grid[i][j];
				else {
					int right = INT_MAX;
					if (j) right = dp[i][j - 1];

					int up = INT_MAX;
					if (i) up = dp[i - 1][j];

					dp[i][j] = grid[i][j] + min(right, up);
				}
			}
		}

		return dp[n - 1][m - 1];
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <vector<int>> grid(n, vector<int> (m));
	for (auto &x : grid) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.minPathSum(grid);

	return 0;
}