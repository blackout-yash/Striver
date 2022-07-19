// 62. Unique Paths
// Link - https://leetcode.com/problems/unique-paths/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector <vector<int>> dp(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) dp[i][j] = 1;
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

	cout << sol.uniquePaths(n, m);

	return 0;
}