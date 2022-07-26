// 69. Rod cutting problem
// Link - https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284



#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
	int cutRod(vector <int> &price, int n) {
		vector <int> dp(n + 1);

		for (int i = 1; i <= n; i++) {
			int ans = 0;
			for (int j = 1; j <= i; j++) {
				int curr = price[j - 1] + dp[i - j];
				ans = max(ans, curr);
			} dp[i] = ans;
		}

		return dp[n];
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