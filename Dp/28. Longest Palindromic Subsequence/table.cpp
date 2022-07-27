// 516. Longest Palindromic Subsequence
// Link - https://leetcode.com/problems/longest-palindromic-subsequence/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int longestPalindromeSubseq(string s) {
		string str1 = s, str2 = s;
		reverse(str2.begin(), str2.end());

		int n = str1.size(), m = str2.size();
		vector <vector<int>> dp(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str1[i] == str2[j]) {
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

	string s;
	cin >> s;

	cout << sol.longestPalindromeSubseq(s);

	return 0;
}