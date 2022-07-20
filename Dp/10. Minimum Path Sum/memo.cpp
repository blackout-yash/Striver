// 64. Minimum Path Sum
// Link - https://leetcode.com/problems/minimum-path-sum/



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
	int minSum(int n, int m, vector <vector<int>> &grid, vector <vector <int>> &dp) {
		if (n == 0 && m == 0) return grid[n][m];
		else if (n < 0 || m < 0) return INT_MAX;
		else if (dp[n][m] != -1) return dp[n][m];

		int left = minSum(n, m - 1, grid, dp);
		int up = minSum(n - 1, m, grid, dp);

		int ans = grid[n][m] + min(left, up);

		return dp[n][m] = ans;
	}

	int minPathSum(vector <vector<int>> &grid) {
		int n = grid.size(), m = grid[0].size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = minSum(n - 1, m - 1, grid, dp);

		return ans;
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