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
		vector <vector<int>> dp(n, vector<int> (n, -1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i) {
					int ans = INT_MAX;
					for (int k = max(0, j - 1); k <= min(n - 1, j + 1); k++) ans = min(ans, dp[i - 1][k]);

					dp[i][j] = ans + matrix[i][j];
				} else dp[i][j] = matrix[i][j];
			}
		}

		int ans = INT_MAX;
		for (int i = 0; i < n; i++) ans = min(ans, dp[n - 1][i]);

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