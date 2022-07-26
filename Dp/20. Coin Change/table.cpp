// 322. Coin Change
// Link - https://leetcode.com/problems/coin-change/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int coinChange(vector<int> &coins, int amount) {
		int n = coins.size();
		vector <vector<int>> dp(n, vector<int> (amount + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= amount; j++) {
				if (j == 0) {
					dp[i][j] = 0;
					continue;
				}

				int notTaken = 1e9;
				if (i) notTaken = dp[i - 1][j];

				int taken = 1e9;
				if (j >= coins[i]) taken = 1 + dp[i][j - coins[i]];

				dp[i][j] = min(taken, notTaken);
			}
		}

		int ans = -1;
		if (dp[n - 1][amount] < 1e9) ans = dp[n - 1][amount];

		return ans;
	}
};

int main() {
	Solution sol;

	int n, amount;
	cin >> n >> amount;

	vector <int> coins(n);
	for (auto &xx : coins) cin >> xx;

	cout << sol.coinChange(coins, amount);

	return 0;
}