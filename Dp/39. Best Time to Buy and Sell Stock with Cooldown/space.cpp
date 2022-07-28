// 309. Best Time to Buy and Sell Stock with Cooldown
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        vector <vector<int>> dp(2, vector<int> (2));
        for (int i = 0; i < n; i++) {
            vector <int> curr(2);
            if (i) {
                int ans1 = -prices[i];
                if (i >= 2) ans1 += dp[0][1];
                int ans2 = dp[1][0];
                curr[0] = max(ans1, ans2);

                int ans3 = prices[i] + dp[1][0];
                int ans4 = dp[1][1];
                curr[1] = max(ans3, ans4);
            } else curr[0] = -prices[i];

            dp[0][0] = dp[1][0]; dp[0][1] = dp[1][1];
            dp[1][0] = curr[0]; dp[1][1] = curr[1];
        }

        return dp[1][1];
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