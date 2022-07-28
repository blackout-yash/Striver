// 44. Wildcard Matching
// Link - https://leetcode.com/problems/wildcard-matching/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	bool isPossible(int n, int m, string &s, string &p, vector <vector<int>> &dp) {
		if (n < -1) return false;
		else if (n < 0 && m < 0) return true;
		else if (m < 0) return false;
		else if (n >= 0 && dp[n][m] != -1) return dp[n][m];

		bool ans = false;
		if (n >= 0 && m >= 0 && (s[n] == p[m] || p[m] == '?')) return ans = isPossible(n - 1, m - 1, s, p, dp);
		else if (m >= 0 && p[m] == '*') {
			for (int i = 0; i <= n + 1; i++) ans |= isPossible(n - i, m - 1, s, p, dp);
		}

		if (n >= 0) dp[n][m] = ans;
		return ans;
	}

	bool isMatch(string s, string p) {
		int n = s.size(), m = p.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		bool ans = isPossible(n - 1, m - 1, s, p, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string s, p;
	cin >> s >> p;

	cout << sol.isMatch(s, p);

	return 0;
}