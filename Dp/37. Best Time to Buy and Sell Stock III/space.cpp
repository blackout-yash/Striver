// 123. Best Time to Buy and Sell Stock III
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), k = 2;
        if (!n) return 0;

        vector <vector<int>> dp(2, vector<int> (k + 1));
        for (int i = 0; i < n; i++) {

            vector <vector<int>> curr(2, vector<int> (k + 1));
            for (int trans = 1; trans <= k; trans++) {
                if (i) {
                    int ans1 = -prices[i] + dp[1][trans - 1];
                    int ans2 = dp[0][trans];
                    curr[0][trans] = max(ans1, ans2);

                    int ans3 = prices[i] + dp[0][trans];
                    int ans4 = dp[1][trans];
                    curr[1][trans] = max(ans3, ans4);
                } else curr[0][trans] = -prices[i];
            }

            for (int trans = 1; trans <= k; trans++) {
                dp[0][trans] = curr[0][trans];
                dp[1][trans] = curr[1][trans];
            }
        }

        return dp[1][k];
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