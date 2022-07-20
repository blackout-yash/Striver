// 63. Unique Paths II
// Link - https://leetcode.com/problems/unique-paths-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
		int n = obstacleGrid.size(), m = obstacleGrid[0].size();
		vector <int> dp(m);

		for (int i = 0; i < n; i++) {

			vector <int> curr(m);
			for (int j = 0; j < m; j++) {
				if (obstacleGrid[i][j]) curr[j] = 0;
				else if (i == 0 && j == 0) curr[j] = 1;
				else {
					int right = 0;
					if (j) right = curr[j - 1];

					int up = 0;
					if (i) up = dp[j];

					curr[j] = right + up;
				}
			}

			for (int j = 0; j < m; j++) dp[j] = curr[j];
		}

		return dp[m - 1];
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