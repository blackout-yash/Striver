// Minimum Number of Deletions and Insertions
// Link - https://www.codingninjas.com/codestudio/problems/can-you-make_4244510



#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
    int canYouMake(string &str, string &ptr) {
        int n = str.size(), m = ptr.size();
        vector <vector<int>> dp(n, vector<int> (m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str[i] == ptr[j]) {
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

        return (n + m) - (2 * dp[n - 1][m - 1]);
    }
};

int main() {
    Solution sol;

    string str, ptr;
    cin >> str >> ptr;

    cout << sol.canYouMake(str, ptr);

    return 0;
}