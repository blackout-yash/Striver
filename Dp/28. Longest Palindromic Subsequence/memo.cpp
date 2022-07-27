// 516. Longest Palindromic Subsequence
// Link - https://leetcode.com/problems/longest-palindromic-subsequence/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxLen(int n, int m, string &st1, string &str2, vector <vector<int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];
		else if (st1[n] == str2[m]) return dp[n][m] = 1 + maxLen(n - 1, m - 1, st1, str2, dp);

		int ans1 = maxLen(n, m - 1, st1, str2, dp);
		int ans2 = maxLen(n - 1, m, st1, str2, dp);

		return dp[n][m] = max(ans1, ans2);
	}


	int longestPalindromeSubseq(string s) {
		string str1 = s, str2 = s;
		reverse(str2.begin(), str2.end());

		int n = str1.size(), m = str2.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = maxLen(n - 1, m - 1, str1, str2, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string s;
	cin >> s;

	cout << sol.longestPalindromeSubseq(s);

	return 0;
}