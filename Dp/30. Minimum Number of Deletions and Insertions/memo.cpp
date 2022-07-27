// Minimum Number of Deletions and Insertions
// Link - https://www.codingninjas.com/codestudio/problems/can-you-make_4244510



#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
	int maxLen(int n, int m, string &str, string &ptr, vector <vector<int>> &dp) {
		if (n < 0 || m < 0) return 0;
		else if (dp[n][m] != -1) return dp[n][m];
		else if (str[n] == ptr[m]) return dp[n][m] = 1 + maxLen(n - 1, m - 1, str, ptr, dp);

		int ans1 = maxLen(n, m - 1, str, ptr, dp);
		int ans2 = maxLen(n - 1, m, str, ptr, dp);

		return dp[n][m] = max(ans1, ans2);
	}

	int canYouMake(string &str, string &ptr) {
		int n = str.size(), m = ptr.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = maxLen(n - 1, m - 1, str, ptr, dp);

		return (n + m) - (2 * ans);
	}
};

int main() {
	Solution sol;

	string str, ptr;
	cin >> str >> ptr;

	cout << sol.canYouMake(str, ptr);

	return 0;
}