// 714. Best Time to Buy and Sell Stock with Transaction Fee
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfitUtil(int n, int fee, bool buy, vector <int> &prices, vector <vector<int>> &dp) {
		if (n < 0) {
			if (buy) return 0;
			return -1e9;
		} else if (dp[n][buy] != -1) return dp[n][buy];

		if (buy) {
			int ans1 = prices[n] + maxProfitUtil(n, fee, !buy, prices, dp);
			int ans2 = maxProfitUtil(n - 1, fee, buy, prices, dp);
			return dp[n][buy] = max(ans1, ans2);
		}

		int ans1 = -prices[n] - fee + maxProfitUtil(n - 1, fee, !buy, prices, dp);
		int ans2 = maxProfitUtil(n - 1, fee, buy, prices, dp);

		return dp[n][buy] = max(ans1, ans2);
	}

	int maxProfit(vector<int> &prices, int fee) {
		int n = prices.size();
		vector <vector<int>> dp(n, vector<int> (2, -1));

		int ans = maxProfitUtil(n - 1, fee, true, prices, dp);

		return ans;
	}
};

int main() {
	Solution sol;

	int n, fee;
	cin >> n >> fee;

	vector <int> prices(n);
	for (auto &xx : prices) cin >> xx;

	cout << sol.maxProfit(prices, fee);

	return 0;
}