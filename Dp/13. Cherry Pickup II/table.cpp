// 1463. Cherry Pickup II
// Link - https://leetcode.com/problems/cherry-pickup-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	int cherryPickup(vector <vector <int>> &grid) {
		int n = grid.size(), m = grid[0].size();

		vector <vector<vector <int>>> dp (n, vector < vector <int>> (m, vector <int> (m)));

		for (int i = n - 1; i >= 0; i--) {
			for (int j1 = 0; j1 < m; j1++) {
				for (int j2 = 0; j2 < m; j2++) {

					if (j1 != j2) {

						int ans = 0;
						if (i + 1 != n) {

							for (int k1 = max(0, j1 - 1); k1 <= min(m - 1, j1 + 1); k1++) {
								for (int k2 = max(0, j2 - 1); k2 <= min(m - 1, j2 + 1); k2++) {

									if (k1 != k2) {
										int curr = dp[i + 1][k1][k2];
										ans = max(ans, curr);
									}
								}
							}
						}

						dp[i][j1][j2] = ans + grid[i][j1] + grid[i][j2];
					}
				}
			}
		}
		return dp[0][0][m - 1];
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