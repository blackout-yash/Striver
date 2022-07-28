// 44. Wildcard Matching
// Link - https://leetcode.com/problems/wildcard-matching/



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        if (n + m == 0) return true;
        else if (!m) return false;
        else if (!n) {
            for (auto x : p) {
                if (x != '*') return false;
            } return true;
        }

        vector <int> dp(m);

        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (s[0] == p[j] || p[j] == '?') {
                if (flag) dp[j] = 1, flag = 0;
                else dp[j] = 0;
            } else if (p[j] == '*') {
                if (j) dp[j] = dp[j - 1];
                else dp[j] = 1;
            } else flag = 0;
        }

        for (int i = 1; i < n; i++) {

            vector <int> curr(m);
            for (int j = 0; j < m; j++) {
                bool ans = false;
                if (j && (s[i] == p[j] || p[j] == '?')) ans |= dp[j - 1];


                if (p[j] == '*') {
                    // If we extend sequence of due to '*' at j.
                    ans |= dp[j];
                    if (j) {
                        // If we take sequence of size 0.
                        ans |= curr[j - 1];
                    } else ans = true;
                }

                curr[j] = ans;
            }

            for (int j = 0; j < m; j++) dp[j] = curr[j];
        }

        return dp[m - 1];
    }
};

int main() {
    Solution sol;

    string s, p;
    cin >> s >> p;

    cout << sol.isMatch(s, p);

    return 0;
}