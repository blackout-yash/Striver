// 63. Unique Paths II
// Link - https://leetcode.com/problems/unique-paths-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalPaths(int n, int m, vector <vector<int>> &obstacleGrid, vector <vector <int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (obstacleGrid[n][m]) return 0;
		else if (n == 0 && m == 0) return 1;
		else if (dp[n][m] != -1) return dp[n][m];

		int left = totalPaths(n, m - 1, obstacleGrid, dp);
		int up = totalPaths(n - 1, m, obstacleGrid, dp);

		int ans = left + up;

		return dp[n][m] = ans;
	}

	int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = totalPaths(n - 1, m - 1, obstacleGrid, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	vector <vector<int>> obstacleGrid(n, vector<int> (m));
	for (auto &x : obstacleGrid) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.uniquePathsWithObstacles(obstacleGrid);

	return 0;
}