// 32. Boolean Evaluation
// Link - https://www.codingninjas.com/codestudio/problems/problem-name-boolean-evaluation_1214650



#include <iostream>
#include <vector>

using namespace std;
#define ll long long
int mod = 1e9 + 7;

class Solution {
public:
    int expression(char ch, int n, int m) {
        if (ch == '&') return (n & m);
        else if (ch == '|') return (n | m);
        return (n ^ m);
    }

    int evaluateExp(string &exp) {
        int n = exp.size();
        vector <vector<vector <ll>>> dp(n + 2, vector<vector <ll>> (n + 2, vector <ll> (2)));

        exp.push_back('&'); exp.push_back('T');
        exp.insert(exp.begin(), '&'); exp.insert(exp.begin(), 'T');


        for (int i = n + 2; i > 1; i--) {
            for (int j = i; j <= n + 1; j++) {
                for (int set = 0; set < 2; set++) {
                    if (i == j) {
                        if (exp[i] == 'T') dp[i][j][set] = (set == 1);
                        else dp[i][j][set] = (set == 0);
                        continue;
                    }
                    ll ans = 0;
                    vector <ll> left(2), right(2);
                    for (int k = i + 1; k < j; k += 2) {
                        left[0] = dp[i][k - 1][0];
                        left[1] = dp[i][k - 1][1];

                        right[0] = dp[k + 1][j][0];
                        right[1] = dp[k + 1][j][1];

                        for (int ind1 = 0; ind1 < 2; ind1++) {
                            for (int ind2 = 0; ind2 < 2; ind2++) {
                                if (expression(exp[k], ind1, ind2) == set) ans = (ans + ((left[ind1] * right[ind2]) % mod)) % mod;
                            }
                        }
                    } dp[i][j][set] = ans;
                }
            }
        }

        return dp[2][n + 1][1];
    }
};

int main() {
    Solution sol;

    string exp;
    cin >> exp;

    cout << sol.evaluateExp(exp);

    return 0;
}