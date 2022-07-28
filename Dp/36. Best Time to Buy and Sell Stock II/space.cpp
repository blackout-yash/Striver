// 122. Best Time to Buy and Sell Stock II
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        int buy = 0, sell;
        for (int i = 0; i < n; i++) {
            int currBuy = 0, currSell;
            if (i) {
                currSell = max(-prices[i] + buy, sell);
                currBuy = max(prices[i] + sell, buy);
            } else currSell = -prices[i];

            buy = currBuy;
            sell = currSell;
        }

        return buy;
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