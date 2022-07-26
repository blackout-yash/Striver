// 518. Coin Change 2
// Link - https://leetcode.com/problems/coin-change-2/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int totalWays(int n, int amount, vector <int> &coins, vector <vector<int>> &dp) {
		if (amount == 0) return 1;
		else if (n == -1 || amount < 0) return 0;
		else if (dp[n][amount] != -1) return dp[n][amount];

		int taken = totalWays(n, amount - coins[n], coins, dp);
		int notTaken = totalWays(n - 1, amount, coins, dp);

		return dp[n][amount] = taken + notTaken;
	}

	int change(int amount, vector<int> &coins) {
		int n = coins.size();
		vector <vector<int>> dp(n, vector<int> (amount + 1, -1));

		int ans = totalWays(n - 1, amount, coins, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, amount;
	cin >> n >> amount;

	vector <int> coins(n);
	for (auto &xx : coins) cin >> xx;

	cout << sol.change(amount, coins);

	return 0;
}