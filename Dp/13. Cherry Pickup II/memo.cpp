// 1463. Cherry Pickup II
// Link - https://leetcode.com/problems/cherry-pickup-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int maxCherry(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector <vector<vector <int>>> &dp) {
		if (i == n) return 0;
		else if (j1 == -1 || j1 == m || j2 == -1 || j2 == m) return 0;
		else if (dp[i][j1][j2] != -1) return dp[i][j1][j2];

		int ans = 0;
		for (int k1 = j1 - 1; k1 <= j1 + 1; k1++) {
			for (int k2 = j2 - 1; k2 <= j2 + 1; k2++) {
				if (k1 != k2) {
					int curr = maxCherry(i + 1, k1, k2, n, m, grid, dp);
					ans = max(ans, curr);
				}
			}
		}

		return dp[i][j1][j2] = ans + grid[i][j1] + grid[i][j2];
	}

	int cherryPickup(vector <vector <int>> &grid) {
		int n = grid.size(), m = grid[0].size();

		vector <vector<vector <int>>> dp (n, vector < vector <int>> (m, vector <int> (m, -1)));

		int ans = maxCherry(0, 0, m - 1, n, m, grid, dp);

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

	cout << sol.cherryPickup(grid);

	return 0;
}