// 72. Edit Distance
// Link - https://leetcode.com/problems/edit-distance/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size(), m = word2.size();
		if (min(n, m) == 0) return max(n, m);

		vector <vector<int>> dp(n, vector<int> (m));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int ans1 = (word1[i] != word2[j]);
				if (i && j) ans1 += dp[i - 1][j - 1];
				else ans1 += (i + j);

				int ans2 = (j + 1) + 1;
				if (i) ans2 = 1 + dp[i - 1][j];

				int ans3 = (i + 1) + 1;
				if (j) ans3 = 1 + dp[i][j - 1];

				dp[i][j] = min({ans1, ans2, ans3});
			}
		}

		return dp[n - 1][m - 1];
	}
};

int main() {
	Solution sol;

	string word1, word2;
	cin >> word1 >> word2;

	cout << sol.minDistance(word1, word2);

	return 0;
}