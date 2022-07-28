// 121. Best Time to Buy and Sell Stock
// Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();

        int _min = 1e9, ans;
        for (int i = 0; i < n; i++) {
            _min = min(_min, prices[i]);

            int curr;
            if (i) curr = max(ans, prices[i] - _min);
            else curr = prices[i] - _min;

            curr = ans;
        }

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