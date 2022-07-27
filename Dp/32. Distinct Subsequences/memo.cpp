// 115. Distinct Subsequences
// Link - https://leetcode.com/problems/distinct-subsequences/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalSeq(int n, int m, string &s, string &t, vector <vector<int>> &dp) {
		if (m < 0) return 1;
		else if (n < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];

		int ans1 = totalSeq(n - 1, m, s, t, dp);
		int ans2 = 0;
		if (s[n] == t[m]) ans2 = totalSeq(n - 1, m - 1, s, t, dp);

		return dp[n][m] = ans1 + ans2;
	}

	int numDistinct(string s, string t) {
		int n = s.size(), m = t.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = totalSeq(n - 1, m - 1, s, t, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string s, t;
	cin >> s >> t;

	cout << sol.numDistinct(s, t);

	return 0;
}