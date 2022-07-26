// 1143. Longest Common Subsequence
// Link - https://leetcode.com/problems/longest-common-subsequence/



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m = text2.size();
		vector <vector<int>> dp(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (text1[i] == text2[j]) {
					int ans = 1;
					if (i && j) ans += dp[i - 1][j - 1];

					dp[i][j] = ans;
				} else {
					int ans1 = 0;
					if (i) ans1 = dp[i - 1][j];

					int ans2 = 0;
					if (j) ans2 = dp[i][j - 1];

					dp[i][j] = max(ans1, ans2);
				}
			}
		}

		return dp[n - 1][m - 1];
	}
};

int main() {
	Solution sol;

	string text1, text2;
	cin >> text1 >> text2;

	cout << sol.longestCommonSubsequence(text1, text2);

	return 0;
}