// 62. Unique Paths
// Link - https://leetcode.com/problems/unique-paths/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalPaths(int n, int m, vector <vector <int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (n == 0 && m == 0) return 1;
		else if (dp[n][m] != -1) return dp[n][m];

		int left = totalPaths(n, m - 1, dp);
		int up = totalPaths(n - 1, m, dp);

		int ans = left + up;

		return dp[n][m] = ans;
	}

	int uniquePaths(int m, int n) {
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = totalPaths(n - 1, m - 1, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, m;
	cin >> n >> m;

	cout << sol.uniquePaths(n, m);

	return 0;
}