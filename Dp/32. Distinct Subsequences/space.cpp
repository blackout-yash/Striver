// 115. Distinct Subsequences
// Link - https://leetcode.com/problems/distinct-subsequences/



#include <iostreamo>
#include <vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector <int> dp(m);

        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {

            vector <int> curr(m);
            for (int j = 0; j < min(i + 1, m); j++) {
                int ans1 = 0;
                if (i) ans1 = dp[j];

                int ans2 = 0;
                if (s[i] == t[j]) {
                    if (i && j) ans2 = dp[j - 1];
                    else ans2++;
                }

                curr[j] = (ans1 + ans2) % mod;
            }

            for (int j = 0; j < m; j++) dp[j] = curr[j];
        }

        return dp[m - 1];
    }
};

int main() {
    Solution sol;

    string s, t;
    cin >> s >> t;

    cout << sol.numDistinct(s, t);

    return 0;
}