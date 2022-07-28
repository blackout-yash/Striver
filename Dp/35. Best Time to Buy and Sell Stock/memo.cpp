// 121. Best Time to Buy and Sell Stock
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfitUtil(int n, int flag, vector <int> &prices, vector <vector<int>> &dp) {
		if (n < 0) {
			if (flag) return -1e9;
			return 1e9;
		} else if (dp[n][flag] != -1) return dp[n][flag];

		if (flag) {
			int ans1 = prices[n] - maxProfitUtil(n, !flag, prices, dp);
			int ans2 = maxProfitUtil(n - 1, flag, prices, dp);
			return dp[n][flag] = max(ans1, ans2);
		}

		int ans1 = prices[n];
		int ans2 = maxProfitUtil(n - 1, flag, prices, dp);

		return dp[n][flag] = min(ans1, ans2);
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