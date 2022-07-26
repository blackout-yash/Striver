// 322. Coin Change
// Link - https://leetcode.com/problems/coin-change/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minValue(int n, int amount, vector <int> &coins, vector <vector<int>> &dp) {
		if (amount == 0) return 0;
		else if (n == -1 || amount < 0) return -1;
		else if (dp[n][amount] != -2) return dp[n][amount];

		int taken = minValue(n, amount - coins[n], coins, dp);
		if (taken != -1) taken += 1;

		int notTaken = minValue(n - 1, amount, coins, dp);

		int ans;
		if (taken == -1 && notTaken == -1) ans = -1;
		else if (taken != -1 && notTaken != -1) ans = min(taken, notTaken);
		else if (taken == -1) ans = notTaken;
		else ans = taken;

		return dp[n][amount] = ans;
	}

	int coinChange(vector<int> &coins, int amount) {
		int n = coins.size();
		vector <vector<int>> dp(n, vector<int> (amount + 1, -2));

		int ans = minValue(n - 1, amount, coins, dp);

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