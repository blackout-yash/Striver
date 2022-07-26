// 1143. Longest Common Subsequence
// Link - https://leetcode.com/problems/longest-common-subsequence/



#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m = text2.size();

		vector <int> dp(m);
		for (int i = 0; i < n; i++) {

			vector <int> curr(m);
			for (int j = 0; j < m; j++) {

				if (text1[i] == text2[j]) {
					int ans = 1;
					if (i && j) ans += dp[j - 1];

					curr[j] = ans;
				} else {
					int ans1 = 0;
					if (i) ans1 = dp[j];

					int ans2 = 0;
					if (j) ans2 = curr[j - 1];

					curr[j] = max(ans1, ans2);
				}
			}

			for (int j = 0; j < m; j++) dp[j] = curr[j];
		}

		return dp[m - 1];
	}
};

int main() {
	Solution sol;

	string text1, text2;
	cin >> text1 >> text2;

	cout << sol.longestCommonSubsequence(text1, text2);

	return 0;
}