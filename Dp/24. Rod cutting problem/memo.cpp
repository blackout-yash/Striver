// 69. Rod cutting problem
// Link - https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
	int maxCost(int n, vector <int> &price, vector <int> &dp) {
		if (n == 0) return 0;
		else if (dp[n] != -1) return dp[n];

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			int curr = price[i - 1] + maxCost(n - i, price, dp);
			ans = max(ans, curr);
		}

		return dp[n] = ans;
	}

	int cutRod(vector <int> &price, int n) {
		vector <int> dp(n + 1, -1);

		int ans = maxCost(n, price, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> price(n);
	for (auto &xx : price) cin >> xx;

	cout << sol.cutRod(price, n);

	return 0;
}