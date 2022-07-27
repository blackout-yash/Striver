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

        vector <int> dp(m);
        for (int i = 0; i < n; i++) {

            vector <int> curr(m);
            for (int j = 0; j < m; j++) {

                if (str[i] == ptr[j]) {
                    int ans = 1;
                    if (i && j) ans += dp[j - 1];

                    curr[j] = ans;
                } else {
                    int ans1 = 0;
                    if (i) ans1 = dp[j];

                    int ans2 = 0;
                    if (j) ans2 = curr[j - 1];

                    curr[j] = max(ans1, ans2);
                }
            }

            for (int j = 0; j < m; j++) dp[j] = curr[j];
        }

        return (n + m) - (2 * dp[m - 1]);
    }
};

int main() {
    Solution sol;

    string str, ptr;
    cin >> str >> ptr;

    cout << sol.canYouMake(str, ptr);

    return 0;
}