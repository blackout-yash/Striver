// 121. Best Time to Buy and Sell Stock
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int n = prices.size();

		vector <int> dp(n);
		int _min = 1e9;
		for (int i = 0; i < n; i++) {
			_min = min(_min, prices[i]);

			if (i) dp[i] = max(dp[i - 1], prices[i] - _min);
			else dp[i] = prices[i] - _min;
		}

		return dp[n - 1];
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