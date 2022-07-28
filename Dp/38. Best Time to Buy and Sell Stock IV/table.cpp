// // 188. Best Time to Buy and Sell Stock IV
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxProfit(int k, vector<int> &prices) {
		int n = prices.size();
		if (!n) return 0;
		vector <vector <vector <int>>> dp(n, vector <vector <int>> (2, vector<int>(k + 1)));

		for (int i = 0; i < n; i++) {
			for (int trans = 1; trans <= k; trans++) {
				if (i) {
					int ans1 = -prices[i] + dp[i - 1][1][trans - 1];
					int ans2 = dp[i - 1][0][trans];
					dp[i][0][trans] = max(ans1, ans2);

					int ans3 = prices[i] + dp[i - 1][0][trans];
					int ans4 = dp[i - 1][1][trans];
					dp[i][1][trans] = max(ans3, ans4);
				} else dp[i][0][trans] = -prices[i];
			}
		}

		return dp[n - 1][1][k];
	}
};

int main() {
	Solution sol;

	int n, k;
	cin >> n >> k;

	vector <int> prices(n);
	for (auto &xx : prices) cin >> xx;

	cout << sol.maxProfit(k, prices);

	return 0;
}