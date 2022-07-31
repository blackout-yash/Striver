// 18. Palindrome Partitioning ll
// Link - https://www.codingninjas.com/codestudio/problems/palindrome-partitioning_873266



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector <vector<int>> store;

	bool isPalindrome(int i, int j, string &s) {
		while (i <= j) {
			if (s[i] != s[j]) return 0;
			i++; j--;
		} return 1;
	}

	void preCompute(int n, string &s) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) store[i][j] = isPalindrome(i, j, s);
		}
	}

	int minCut(int i, int j, string &s, vector <vector<int>> &dp) {
		if (store[i][j]) return 0;
		else if (dp[i][j] != -1) return dp[i][j];

		int ans = 1e9;
		for (int k = i; k < j; k++) {
			int left = minCut(i, k, s, dp);
			int right = minCut(k + 1, j, s, dp);
			ans = min(ans, left + 1 + right);
		} return dp[i][j] = ans;
	}

	int palindromePartitioning(string s) {
		int n = s.size();

		store.clear(); store.resize(n, vector <int> (n));
		preCompute(n, s);

		vector <vector<int>> dp(n, vector<int> (n, -1));
		int ans = minCut(0, n - 1, s, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string s;
	cin >> s;

	cout << sol.palindromePartitioning(s);

	return 0;
}