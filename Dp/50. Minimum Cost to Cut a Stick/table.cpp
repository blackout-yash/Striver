// 1547. Minimum Cost to Cut a Stick
// Link - https://leetcode.com/problems/minimum-cost-to-cut-a-stick/



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minCost(int i, int j, vector <int> &cuts, vector <vector<int>> &dp) {
        if (i > j) return 0;
        else if (dp[i][j] != -1) return dp[i][j];

        int ans = 1e9;
        for (int k = i; k <= j; k++) {
            int left = minCost(i, k - 1, cuts, dp);
            int right = minCost(k + 1, j, cuts, dp);
            int curr = cuts[j + 1] - cuts[i - 1];
            ans = min(ans, left + curr + right);
        }

        return dp[i][j] = ans;
    }

    int minCost(int n, vector<int> &cuts) {
        int c = cuts.size();
        vector <vector<int>> dp(c + 2, vector<int> (c + 2));

        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        for (int i = c; i > 0; i--) {
            for (int j = i; j <= c; j++) {
                int ans = 1e9;
                for (int k = i; k <= j; k++) {
                    int left = dp[i][k - 1];
                    int right = dp[k + 1][j];
                    int curr = cuts[j + 1] - cuts[i - 1];
                    ans = min(ans, left + curr + right);
                } dp[i][j] = ans;
            }
        }

        return dp[1][c];
    }
};

int main() {
    Solution sol;

    int n, m;
    cin >> n >> m;

    vector <int> cuts(m);
    for (auto &xx : cuts) cin >> xx;

    cout << sol.minCost(n, cuts);

    return 0;
}