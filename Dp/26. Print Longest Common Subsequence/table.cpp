// The Longest Common Subsequence (LCS)
// Link - hackerrank.com/challenges/linkedin-practice-dynamic-programming-lcs/problem?isFullScreen=false



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void maxLen(int n, int m, vector <int> &a, vector <int> &b, vector <vector<int>> &dp) {

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    int ans = 1;
                    if (i && j) ans += dp[i - 1][j - 1];

                    dp[i][j] = ans;
                } else {
                    int ans1 = 0;
                    if (i) ans1 = dp[i - 1][j];

                    int ans2 = 0;
                    if (j) ans2 = dp[i][j - 1];

                    dp[i][j] = max(ans1, ans2);
                }
            }
        }
    }

    vector <int> findLcs(int n, int m, vector <int> &a, vector <int> &b, vector <vector<int>> &dp) {
        vector <int> ans;
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] == b[j]) {
                ans.push_back(a[i]);
                i--; j--;
            } else {
                int ans1 = 0;
                if (i) ans1 = dp[i - 1][j];

                int ans2 = 0;
                if (j) ans2 = dp[i][j - 1];

                if (ans1 >= ans2) i--;
                else j--;
            }
        } reverse(ans.begin(), ans.end());

        return ans;
    }

    vector <int> lcs(int n, int m, vector <int> &a, vector <int> &b) {

        vector <vector<int>> dp(n, vector<int> (m));
        maxLen(n, m, a, b, dp);

        vector <int> ans = findLcs(n, m, a, b, dp);

        return ans;
    }
};

int main() {
    Solution sol;

    int n, m;
    cin >> n >> m;

    vector <int> a(n);
    for (auto &xx : a) cin >> xx;

    vector <int> b(m);
    for (auto &xx : b) cin >> xx;

    vector <int> ans = sol.lcs(n, m, a, b);

    for (auto xx : ans) cout << xx << " ";

    return 0;
}