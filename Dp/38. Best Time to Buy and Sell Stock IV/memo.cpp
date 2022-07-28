// 188. Best Time to Buy and Sell Stock IV
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitUtil(int n, int k, bool buy, vector <int> &prices, vector <vector <vector <int>>> &dp) {
        if (n < 0) {
            if (buy) return 0;
            return -1e9;
        } else if (k == 0 && buy) return 0;
        else if (dp[n][buy][k] != -1) return dp[n][buy][k];

        if (buy) {
            int ans1 = prices[n] + maxProfitUtil(n, k - 1, !buy, prices, dp);
            int ans2 = maxProfitUtil(n - 1, k, buy, prices, dp);
            return dp[n][buy][k] = max(ans1, ans2);
        }

        int ans1 = -prices[n] + maxProfitUtil(n - 1, k, !buy, prices, dp);
        int ans2 = maxProfitUtil(n - 1, k, buy, prices, dp);

        return dp[n][buy][k] = max(ans1, ans2);
    }

    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector <vector <vector <int>>> dp(n, vector <vector <int>> (2, vector<int>(k + 1, -1)));

        int ans = maxProfitUtil(n - 1, k, true, prices, dp);

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