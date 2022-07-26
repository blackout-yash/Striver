// 322. Coin Change
// Link - https://leetcode.com/problems/coin-change/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minValue(int n, int amount, vector <int> &coins, vector <vector<int>> &dp) {
		if (amount == 0) return 0;
		else if (n == -1 || amount < 0) return 1e9;
		else if (dp[n][amount] != -1) return dp[n][amount];

		int taken = 1 + minValue(n, amount - coins[n], coins, dp);

		int notTaken = minValue(n - 1, amount, coins, dp);

		return dp[n][amount] = min(taken, notTaken);
	}

	int coinChange(vector<int> &coins, int amount) {
		int n = coins.size();
		vector <vector<int>> dp(n, vector<int> (amount + 1, -1));

		int ans = minValue(n - 1, amount, coins, dp);
		if (ans >= 1e9) ans = -1;

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