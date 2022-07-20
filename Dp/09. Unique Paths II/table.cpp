// 63. Unique Paths II
// Link - https://leetcode.com/problems/unique-paths-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		vector <vector<int>> dp(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (obstacleGrid[i][j]) dp[i][j] = 0;
				else if (i == 0 && j == 0) dp[i][j] = 1;
				else {
					int right = 0;
					if (j) right = dp[i][j - 1];

					int up = 0;
					if (i) up = dp[i - 1][j];

					dp[i][j] = right + up;
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

	vector <vector<int>> obstacleGrid(n, vector<int> (m));
	for (auto &x : obstacleGrid) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.uniquePathsWithObstacles(obstacleGrid);

	return 0;
}