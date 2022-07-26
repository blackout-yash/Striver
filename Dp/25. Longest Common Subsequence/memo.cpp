// 1143. Longest Common Subsequence
// Link - https://leetcode.com/problems/longest-common-subsequence/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxLen(int n, int m, string &text1, string &text2, vector <vector<int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];
		else if (text1[n] == text2[m]) return dp[n][m] = 1 + maxLen(n - 1, m - 1, text1, text2, dp);

		int ans1 = maxLen(n, m - 1, text1, text2, dp);
		int ans2 = maxLen(n - 1, m, text1, text2, dp);

		return dp[n][m] = max(ans1, ans2);
	}

	int longestCommonSubsequence(string text1, string text2) {
		int n = text1.size(), m = text2.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = maxLen(n - 1, m - 1, text1, text2, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string text1, text2;
	cin >> text1 >> text2;

	cout << sol.longestCommonSubsequence(text1, text2);

	return 0;
}