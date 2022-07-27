// 1092. Shortest Common Supersequence
// Link - https://leetcode.com/problems/shortest-common-supersequence/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxLen(int n, int m, string &str1, string &str2, vector <vector<int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];
		else if (str1[n] == str2[m]) return dp[n][m] = 1 + maxLen(n - 1, m - 1, str1, str2, dp);

		int ans1 = maxLen(n, m - 1, str1, str2, dp);
		int ans2 = maxLen(n - 1, m, str1, str2, dp);

		return dp[n][m] = max(ans1, ans2);
	}

	string findLcs(int n, int m, string &str1, string &str2, vector <vector<int>> &dp) {
		string ans;
		int i = n - 1, j = m - 1;
		while (i >= 0 && j >= 0) {
			if (str1[i] == str2[j]) {
				ans.push_back(str1[i]);
				i--; j--;
			} else {
				int ans1 = 0;
				if (i) ans1 = dp[i - 1][j];

				int ans2 = 0;
				if (j) ans2 = dp[i][j - 1];

				if (ans1 >= ans2) i--;
				else j--;
			}
		} reverse(ans.begin(), ans.end());

		return ans;
	}

	string shortestCommonSupersequence(string str1, string str2) {
		int n = str1.size(), m = str2.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));
		maxLen(n - 1, m - 1, str1, str2, dp);

		string curr = findLcs(n, m, str1, str2, dp), ans;

		int i = 0, j = 0, k = 0, l = curr.size();
		while (i < n || j < m) {
			if (k == l) {
				if (i != n) ans.push_back(str1[i++]);
				if (j != m) ans.push_back(str2[j++]);
			} else {
				if (i != n && str1[i] != curr[k]) ans.push_back(str1[i++]);

				if (j != m && str2[j] != curr[k]) ans.push_back(str2[j++]);

				if (str1[i] == curr[k] && str2[j] == curr[k]) {
					ans.push_back(curr[k++]);
					i++; j++;
				}
			}
		}

		return ans;
	}
};

int main() {
	Solution sol;

	string str1, str2;
	cin >> str1 >> str2;

	cout << sol.shortestCommonSupersequence(str1, str2);

	return 0;
}