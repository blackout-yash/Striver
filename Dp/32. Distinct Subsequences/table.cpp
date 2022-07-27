// 115. Distinct Subsequences
// Link - https://leetcode.com/problems/distinct-subsequences/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector <vector<int>> dp(n, vector<int> (m));

        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < min(i + 1, m); j++) {
                int ans1 = 0;
                if (i) ans1 = dp[i - 1][j];

                int ans2 = 0;
                if (s[i] == t[j]) {
                    if (i && j) ans2 = dp[i - 1][j - 1];
                    else ans2++;
                }

                dp[i][j] = (ans1 + ans2) % mod;
            }
        }

        return dp[n - 1][m - 1];
    }
};

int main() {
    Solution sol;

    string s, t;
    cin >> s >> t;

    cout << sol.numDistinct(s, t);

    return 0;
}