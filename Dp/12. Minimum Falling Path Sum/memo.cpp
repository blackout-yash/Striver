// 931. Minimum Falling Path Sum
// Link - https://leetcode.com/problems/minimum-falling-path-sum/



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
	int minSum(int i, int j, int n, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
		if (i == n) return 0;
		else if (j == -1 || j == n) return INT_MAX;
		else if (dp[i][j] != -1) return dp[i][j];

		int ans = INT_MAX;
		for (int k = j - 1; k <= j + 1; k++) {
			int curr = minSum(i + 1, k, n, matrix, dp);
			ans = min(ans, curr);
		}

		return dp[i][j] = ans + matrix[i][j];
	}

	int minFallingPathSum(vector<vector<int>> &matrix) {
		int n = matrix.size();
		vector <vector<int>> dp(n, vector<int> (n, -1));

		int ans = INT_MAX;
		for (int i = 0; i < n; i++) {
			int curr = minSum(0, i, n, matrix, dp);
			ans = min(ans, curr);
		}

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