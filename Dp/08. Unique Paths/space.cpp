// 62. Unique Paths
// Link - https://leetcode.com/problems/unique-paths/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {

		vector <int> dp(m);
		for (int i = 0; i < n; i++) {

			vector <int> curr(m);
			for (int j = 0; j < m; j++) {
				if (i == 0 && j == 0) curr[j] = 1;
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

	cout << sol.uniquePaths(n, m);

	return 0;
}