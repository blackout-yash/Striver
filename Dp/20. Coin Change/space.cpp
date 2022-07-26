// 322. Coin Change
// Link - https://leetcode.com/problems/coin-change/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int coinChange(vector<int> &coins, int amount) {
		int n = coins.size();

		vector <int> dp(amount + 1);
		for (int i = 0; i < n; i++) {

			vector <int> curr(amount + 1);
			for (int j = 0; j <= amount; j++) {
				if (j == 0) {
					curr[j] = 0;
					continue;
				}

				int notTaken = 1e9;
				if (i) notTaken = dp[j];

				int taken = 1e9;
				if (j >= coins[i]) taken = 1 + curr[j - coins[i]];

				curr[j] = min(taken, notTaken);
			}

			for (int j = 0; j <= amount; j++) dp[j] = curr[j];
		}

		int ans = -1;
		if (dp[amount] < 1e9) ans = dp[amount];

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