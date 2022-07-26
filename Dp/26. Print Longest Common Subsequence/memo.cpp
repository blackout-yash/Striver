// The Longest Common Subsequence (LCS)
// Link - hackerrank.com/challenges/linkedin-practice-dynamic-programming-lcs/problem?isFullScreen=false



#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxLen(int n, int m, vector <int> &a, vector <int> &b, vector <vector<int>> &dp) {
        if (n < 0 || m < 0) return 0;
        else if (dp[n][m] != -1) return dp[n][m];
        else if (a[n] == b[m]) return dp[n][m] = 1 + maxLen(n - 1, m - 1, a, b, dp);

        int ans1 = maxLen(n, m - 1, a, b, dp);
        int ans2 = maxLen(n - 1, m, a, b, dp);

        return dp[n][m] = max(ans1, ans2);
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

        vector <vector<int>> dp(n, vector<int> (m, -1));
        maxLen(n - 1, m - 1, a, b, dp);

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