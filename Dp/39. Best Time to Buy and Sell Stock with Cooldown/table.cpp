// 309. Best Time to Buy and Sell Stock with Cooldown
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector <vector<int>> dp(n, vector<int> (2));

        for (int i = 0; i < n; i++) {
            if (i) {
                int ans1 = -prices[i];
                if (i >= 2) ans1 += dp[i - 2][1];
                int ans2 = dp[i - 1][0];
                dp[i][0] = max(ans1, ans2);

                int ans3 = prices[i] + dp[i - 1][0];
                int ans4 = dp[i - 1][1];
                dp[i][1] = max(ans3, ans4);
            } else dp[i][0] = -prices[i];
        }

        return dp[n - 1][1];
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