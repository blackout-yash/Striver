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

	int palindromePartitioning(string s) {
		int n = s.size();

		store.clear(); store.resize(n, vector <int> (n));
		preCompute(n, s);

		vector <vector<int>> dp(n, vector<int> (n));
		for (int i = n - 1; i >= 0; i--) {
			for (int j = i; j < n; j++) {
				if (store[i][j]) continue;

				int ans = 1e9;
				for (int k = i; k < j; k++) {
					int left = dp[i][k];
					int right = dp[k + 1][j];
					ans = min(ans, left + 1 + right);
				} dp[i][j] = ans;
			}
		}

		return dp[0][n - 1];
	}
};

int main() {
	Solution sol;

	string s;
	cin >> s;

	cout << sol.palindromePartitioning(s);

	return 0;
}