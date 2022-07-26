// 518. Coin Change 2
// Link - https://leetcode.com/problems/coin-change-2/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int change(int amount, vector<int> &coins) {
		int n = coins.size();
		vector <vector<int>> dp(n, vector<int> (amount + 1));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= amount; j++) {
				if (j == 0) {
					dp[i][j] = 1;
					continue;
				}

				int notTaken = 0;
				if (i) notTaken = dp[i - 1][j];

				int taken = 0;
				if (j >= coins[i]) taken = dp[i][j - coins[i]];

				dp[i][j] = taken + notTaken;
			}
		}

		return dp[n - 1][amount];
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