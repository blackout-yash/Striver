// 931. Minimum Falling Path Sum
// Link - https://leetcode.com/problems/minimum-falling-path-sum/



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:

	int minFallingPathSum(vector<vector<int>> &matrix) {
		int n = matrix.size();

		vector <int> dp(n);
		for (int i = 0; i < n; i++) {

			vector <int> curr(n);
			for (int j = 0; j < n; j++) {
				if (i) {
					int ans = INT_MAX;
					for (int k = max(0, j - 1); k <= min(n - 1, j + 1); k++) ans = min(ans, dp[k]);

					curr[j] = ans + matrix[i][j];
				} else curr[j] = matrix[i][j];
			}

			for (int j = 0; j < n; j++) dp[j] = curr[j];
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; i++) ans = min(ans, dp[i]);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <vector<int>> matrix(n, vector<int> (n));
	for (auto &x : matrix) {
		for (auto &y : x) cin >> y;
	}

	cout << sol.minFallingPathSum(matrix);

	return 0;
}