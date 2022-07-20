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
		vector <int> dp(m);

		for (int i = 0; i < n; i++) {

			vector <int> curr(m);
			for (int j = 0; j < m; j++) {

				if (i == 0 && j == 0) curr[j] = grid[i][j];
				else {
					int right = INT_MAX;
					if (j) right = curr[j - 1];

					int up = INT_MAX;
					if (i) up = dp[j];

					curr[j] = grid[i][j] + min(right, up);
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

	vector <vector<int>> grid(n, vector<int> (m));
	for (auto &x : grid) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.minPathSum(grid);

	return 0;
}