// 72. Edit Distance
// Link - https://leetcode.com/problems/edit-distance/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minOperations(int n, int m, string &word1, string &word2, vector <vector<int>> &dp) {
		if (m < 0) return n + 1;
		else if (n < 0) return m + 1;
		else if (dp[n][m] != -1) return dp[n][m];

		int ans1 = minOperations(n - 1, m - 1, word1, word2, dp);
		if (word1[n] != word2[m]) ans1 += 1;

		int ans2 = 1 + minOperations(n - 1, m, word1, word2, dp);
		int ans3 = 1 + minOperations(n, m - 1, word1, word2, dp);

		return dp[n][m] = min({ans1, ans2, ans3});
	}

	int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		vector <vector<int>> dp(n, vector<int> (m, -1));

		int ans = minOperations(n - 1, m - 1, word1, word2, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	string word1, word2;
	cin >> word1 >> word2;

	cout << sol.minDistance(word1, word2);

	return 0;
}