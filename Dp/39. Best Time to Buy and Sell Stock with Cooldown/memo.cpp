// 309. Best Time to Buy and Sell Stock with Cooldown
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfitUtil(int n, bool buy, vector <int> &prices, vector <vector<int>> &dp) {
		if (n < 0) {
			if (buy) return 0;
			return -1e9;
		} else if (dp[n][buy] != -1) return dp[n][buy];

		if (buy) {
			int ans1 = prices[n] + maxProfitUtil(n, !buy, prices, dp);
			int ans2 = maxProfitUtil(n - 1, buy, prices, dp);
			return dp[n][buy] = max(ans1, ans2);
		}

		int ans1 = -prices[n] + maxProfitUtil(n - 2, !buy, prices, dp);
		int ans2 = maxProfitUtil(n - 1, buy, prices, dp);
		return dp[n][buy] = max(ans1, ans2);
	}

	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		vector <vector<int>> dp(n, vector<int> (2, -1));

		int ans = maxProfitUtil(n - 1, 1, prices, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n;
	cin >> n;

	vector <int> prices(n);
	for (auto &xx : prices) cin >> xx;

	cout << sol.maxProfit(prices);

	return 0;
}