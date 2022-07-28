// This is giving TLE on leetcode.


// 123. Best Time to Buy and Sell Stock III
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitUtil(int n, int k, int flag, vector <int> &prices, vector <vector <vector <int>>> &dp) {
        if (n < 0) {
            if (flag) return 0;
            return -1e9;
        } else if (k == 0 && flag) return 0;
        else if (dp[n][flag][k] != -1) return dp[n][flag][k];

        if (flag) {
            int ans1 = prices[n] + maxProfitUtil(n, k - 1, !flag, prices, dp);
            int ans2 = maxProfitUtil(n - 1, k, flag, prices, dp);
            return dp[n][flag][k] = max(ans1, ans2);
        }

        int ans1 = -prices[n] + maxProfitUtil(n - 1, k, !flag, prices, dp);
        int ans2 = maxProfitUtil(n - 1, k, flag, prices, dp);

        return dp[n][flag][k] = max(ans1, ans2);
    }

    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector <vector <vector <int>>> dp(n, vector <vector <int>> (2, vector<int>(3, -1)));
        int ans = maxProfitUtil(n - 1, 2, 1, prices, dp);

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