// 29. Longest Common Substring
// Link - https://www.codingninjas.com/codestudio/problems/longest-common-substring_1235207



#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lcs(string &str1, string &str2) {
        int n = str1.size(), m = str2.size(), ans = 0;
        vector <vector<int>> dp(n, vector<int> (m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (str1[i] == str2[j]) {
                    int curr = 0;
                    if (i && j) curr = dp[i - 1][j - 1];

                    ans = max(ans, 1 + curr);
                    dp[i][j] = 1 + curr;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string str1, str2;
    cin >> str1 >> str2;

    cout << sol.lcs(str1, str2);

    return 0;
}