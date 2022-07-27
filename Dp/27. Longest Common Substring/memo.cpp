// 29. Longest Common Substring
// Link - https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxLen(int n, int m, int &ans, string &str1, string &str2, vector <vector<int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];

		maxLen(n - 1, m, ans, str1, str2, dp);
		maxLen(n, m - 1, ans, str1, str2, dp);

		int curr = 0;
		if (str1[n] == str2[m]) {
			curr = 1 + maxLen(n - 1, m - 1, ans, str1, str2, dp);
			ans = max(ans, curr);
		}

		return dp[n][m] = curr;
	}

	int lcs(string &str1, string &str2) {
		int n = str1.size(), m = str2.size(), ans = 0;
		vector <vector<int>> dp(n, vector<int> (m, -1));

		maxLen(n - 1, m - 1, ans, str1, str2, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string str1, str2;
	cin >> str1 >> str2;

	cout << sol.lcs(str1, str2);

	return 0;
}